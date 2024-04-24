//==============================================================
// Copyright (C) Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

#ifndef PTI_TOOLS_UNITRACE_LEVEL_ZERO_COLLECTOR_H_
#define PTI_TOOLS_UNITRACE_LEVEL_ZERO_COLLECTOR_H_

#include <chrono>
#include <atomic>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <dlfcn.h>

#include <level_zero/ze_api.h>
#include <level_zero/layers/zel_tracing_api.h>

#include "correlator.h" // utils
#include "utils.h" // utils
#include "ze_event_cache.h"
#include "ze_utils.h" // utils
#include "collector_options.h"
#include "unikernel.h"
#include "unitimer.h"
#include "unicontrol.h"
#include "unimemory.h"

#include "common_header.gen"

enum ZeKernelCommandType {
  KERNEL_COMMAND_TYPE_INVALID = 0,
  KERNEL_COMMAND_TYPE_COMPUTE = 1,
  KERNEL_COMMAND_TYPE_MEMORY = 2,
  KERNEL_COMMAND_TYPE_COMMAND = 3
};

struct ZeCommandMetricQuery {
  uint64_t instance_id_ = 0;	//unique kernel or command instance identifier
  zet_metric_query_handle_t metric_query_ = nullptr;
  ze_event_handle_t metric_query_event_ = nullptr;
  ze_device_handle_t device_ = nullptr;
  ZeKernelCommandType type_;
  bool immediate_;
};

struct ZeKernelGroupSize {
  uint32_t x;
  uint32_t y;
  uint32_t z;
};

struct ZeMetricQueryPoolKey {
  ze_context_handle_t context_;
  ze_device_handle_t device_;
  zet_metric_group_handle_t group_;
};

struct ZeKernelCommandNameKey {
  uint64_t kernel_command_id_;
  uint64_t mem_size_;
  int tile_;
  ze_group_count_t group_count_;

  bool operator>(const ZeKernelCommandNameKey& r) const {
    if (kernel_command_id_ != r.kernel_command_id_) {
      return kernel_command_id_ > r.kernel_command_id_;
    }
    if (mem_size_ != r.mem_size_) {
      return mem_size_ > r.mem_size_;
    }
    if (tile_ != r.tile_) {
      return tile_ > r.tile_;
    }
    
    if (group_count_.groupCountX != r.group_count_.groupCountX) {
      return (group_count_.groupCountX > r.group_count_.groupCountX);
    }

    if (group_count_.groupCountY != r.group_count_.groupCountY) {
      return (group_count_.groupCountY > r.group_count_.groupCountY);
    }

    return (group_count_.groupCountZ > r.group_count_.groupCountZ);
  }

  bool operator!=(const ZeKernelCommandNameKey& r) const {
    if (kernel_command_id_ == r.kernel_command_id_) {
      if (mem_size_ == r.mem_size_) {
        if (tile_ == r.tile_) {
          return ((group_count_.groupCountX != r.group_count_.groupCountX) ||
              (group_count_.groupCountX != r.group_count_.groupCountX) || (group_count_.groupCountX != r.group_count_.groupCountX));
        }
      }
    }

    return true;
  }
};
struct ZeKernelCommandTime {
  uint64_t append_time_;
  uint64_t submit_time_;
  uint64_t execute_time_;
  uint64_t min_time_;
  uint64_t max_time_;
  uint64_t call_count_;

  bool operator>(const ZeKernelCommandTime& r) const {
    if (execute_time_ != r.execute_time_) {
      return execute_time_ > r.execute_time_;
    }
    return call_count_ > r.call_count_;
  }

  bool operator!=(const ZeKernelCommandTime& r) const {
    if (execute_time_ == r.execute_time_) {
      return call_count_ != r.call_count_;
    }
    return true;
  }
};
struct ZeKernelCommandNameKeyCompare {
  bool operator()(const ZeKernelCommandNameKey& lhs, const ZeKernelCommandNameKey& rhs) const {
    if (lhs.kernel_command_id_ != rhs.kernel_command_id_) {
      return (lhs.kernel_command_id_ < rhs.kernel_command_id_);
    }
    if (lhs.mem_size_ != rhs.mem_size_) {
      return (lhs.mem_size_ < rhs.mem_size_);
    }
    if (lhs.tile_ != rhs.tile_) {
      return (lhs.tile_ < rhs.tile_);
    }
    if (lhs.group_count_.groupCountX != rhs.group_count_.groupCountX) {
      return (lhs.group_count_.groupCountX < rhs.group_count_.groupCountX);
    }
    if (lhs.group_count_.groupCountY != rhs.group_count_.groupCountY) {
      return (lhs.group_count_.groupCountY < rhs.group_count_.groupCountY);
    }
    if (lhs.group_count_.groupCountZ != rhs.group_count_.groupCountZ) {
      return (lhs.group_count_.groupCountZ < rhs.group_count_.groupCountZ);
    }
    return false;
  }
};

struct ZeFunctionTime {
  uint64_t total_time_;
  uint64_t min_time_;
  uint64_t max_time_;
  uint64_t call_count_;

  bool operator>(const ZeFunctionTime& r) const {
    if (total_time_ != r.total_time_) {
      return total_time_ > r.total_time_;
    }
    return call_count_ > r.call_count_;
  }

  bool operator!=(const ZeFunctionTime& r) const {
    if (total_time_ == r.total_time_) {
      return call_count_ != r.call_count_;
    }
    return true;
  }
};


struct ZeInstanceData {
  uint64_t start_time_host;	// in ns
  uint64_t timestamp_host;	// in ns
  uint64_t timestamp_device;	// in ticks
  uint64_t kid;	// passing kid from enter callback to exit callback
};

thread_local ZeInstanceData ze_instance_data;


static std::mutex global_device_time_stats_mutex_;
static std::map<ZeKernelCommandNameKey, ZeKernelCommandTime, ZeKernelCommandNameKeyCompare> *global_device_time_stats_;

void SweepKernelCommandTimeStats(std::map<ZeKernelCommandNameKey, ZeKernelCommandTime, ZeKernelCommandNameKeyCompare>& stats) {
  global_device_time_stats_mutex_.lock();
  if (global_device_time_stats_ == nullptr) {
    global_device_time_stats_ = new std::map<ZeKernelCommandNameKey, ZeKernelCommandTime, ZeKernelCommandNameKeyCompare>;
    UniMemory::ExitIfOutOfMemory((void *)(global_device_time_stats_));
  }
  for (auto it = stats.begin(); it != stats.end(); it++) {
    auto it2 = global_device_time_stats_->find(it->first);
    if (it2 == global_device_time_stats_->end()) {
      ZeKernelCommandTime stat;
      stat.append_time_ = it->second.append_time_;
      stat.submit_time_ = it->second.submit_time_;
      stat.execute_time_ = it->second.execute_time_;
      stat.min_time_ = it->second.min_time_;
      stat.max_time_ = it->second.max_time_;
      stat.call_count_ = it->second.call_count_;
      global_device_time_stats_->insert({it->first, std::move(stat)});
    }
    else {
      it2->second.append_time_ += it->second.append_time_;
      it2->second.submit_time_ +=  it->second.submit_time_;
      it2->second.execute_time_ += it->second.execute_time_;
      if (it->second.max_time_ > it2->second.max_time_) {
        it2->second.max_time_ = it->second.max_time_;
      }
      if (it->second.min_time_ < it2->second.min_time_) {
        it2->second.min_time_ = it->second.min_time_;
      }
      it2->second.call_count_ += it->second.call_count_;
    }
  }
  global_device_time_stats_mutex_.unlock();
}

static std::mutex global_host_time_stats_mutex_;
static std::map<uint32_t, ZeFunctionTime> *global_host_time_stats_;

void SweepHostFunctionTimeStats(std::map<uint32_t, ZeFunctionTime>& stats) {
  global_host_time_stats_mutex_.lock();
  if (global_host_time_stats_ == nullptr) {
    global_host_time_stats_ = new std::map<uint32_t, ZeFunctionTime>;
    UniMemory::ExitIfOutOfMemory((void *)(global_host_time_stats_));
  }
  for (auto it = stats.begin(); it != stats.end(); it++) {
    auto it2 = global_host_time_stats_->find(it->first);
    if (it2 == global_host_time_stats_->end()) {
      ZeFunctionTime stat;
      stat.total_time_ = it->second.total_time_;
      stat.min_time_ = it->second.min_time_;
      stat.max_time_ = it->second.max_time_;
      stat.call_count_ = it->second.call_count_;
      global_host_time_stats_->insert({it->first, std::move(stat)});
    }
    else {
      it2->second.total_time_ += it->second.total_time_;
      if (it->second.max_time_ > it2->second.max_time_) {
        it2->second.max_time_ = it->second.max_time_;
      }
      if (it->second.min_time_ < it2->second.min_time_) {
        it2->second.min_time_ = it->second.min_time_;
      }
      it2->second.call_count_ += it->second.call_count_;
    }
  }
  global_host_time_stats_mutex_.unlock();
}


struct ZeMetricQueryPoolKeyCompare {
  bool operator()(const ZeMetricQueryPoolKey& lhs, const ZeMetricQueryPoolKey& rhs) const {
    if (lhs.context_ < rhs.context_) {
      return true;
    }
    if (lhs.context_ == rhs.context_) {
      if (lhs.device_ < rhs.device_) {
        return true;
      }
      if (lhs.device_ == rhs.device_) {
        return (lhs.group_ < rhs.group_);
      }
    }
    return false;
  }
};

struct ZeMetricQueryPools {
  constexpr static uint32_t pool_size_ = 128;
  std::mutex query_pool_mutex_;
  std::map<zet_metric_query_handle_t, ZeMetricQueryPoolKey> query_pool_map_;
  std::map<ZeMetricQueryPoolKey, std::vector<zet_metric_query_handle_t>, ZeMetricQueryPoolKeyCompare> free_pool_;
  std::vector<zet_metric_query_pool_handle_t> pools_;

  ZeMetricQueryPools() {}
  
  ZeMetricQueryPools(const struct ZeMetricQueryPools& that) = delete;

  ZeMetricQueryPools& operator=(const struct ZeMetricQueryPools& that) = delete;

  ~ZeMetricQueryPools() {
    ze_result_t status;

    const std::lock_guard<std::mutex> lock(query_pool_mutex_);
    for (auto it = query_pool_map_.begin(); it != query_pool_map_.end(); it++) {
      status = zetMetricQueryDestroy(it->first);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    }
    query_pool_map_.clear();

    for (auto it = pools_.begin(); it != pools_.end(); it++) {
      status = zetMetricQueryPoolDestroy(*it);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    }
    
    pools_.clear();

    free_pool_.clear();
  }

  zet_metric_query_handle_t
  GetQuery(ze_context_handle_t context, ze_device_handle_t device, zet_metric_group_handle_t group) {
    ze_result_t status;
    zet_metric_query_handle_t query;

    const std::lock_guard<std::mutex> lock(query_pool_mutex_);
    auto it = free_pool_.find({context, device, group});
    if (it == free_pool_.end()) {
      // no pools created

      zet_metric_query_pool_desc_t desc = {ZET_STRUCTURE_TYPE_METRIC_QUERY_POOL_DESC, nullptr, ZET_METRIC_QUERY_POOL_TYPE_PERFORMANCE, pool_size_};
      zet_metric_query_pool_handle_t pool;

      status = zetMetricQueryPoolCreate(context, device, group, &desc, &pool);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
      pools_.push_back(pool);

      std::vector<zet_metric_query_handle_t> queries;
      for (int i = 0; i < pool_size_ - 1; i++) {
        status = zetMetricQueryCreate(pool, i, &query);
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);
        queries.push_back(query);
        query_pool_map_.insert({query, {context, device, group}});
      }
      status = zetMetricQueryCreate(pool, pool_size_ - 1, &query);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
      query_pool_map_.insert({query, {context, device, group}});
      
      free_pool_.insert({{context, device, group}, std::move(queries)});
    }
    else {
      if (it->second.size() == 0) {
        // no free queries, create a new pool

        zet_metric_query_pool_desc_t desc = {ZET_STRUCTURE_TYPE_METRIC_QUERY_POOL_DESC, nullptr, ZET_METRIC_QUERY_POOL_TYPE_PERFORMANCE, pool_size_};
        zet_metric_query_pool_handle_t pool;

        status = zetMetricQueryPoolCreate(context, device, group, &desc, &pool);
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);
        pools_.push_back(pool);

        for (int i = 0; i < pool_size_ - 1; i++) {
          status = zetMetricQueryCreate(pool, i, &query);
          PTI_ASSERT(status == ZE_RESULT_SUCCESS);
          it->second.push_back(query);
          query_pool_map_.insert({query, {context, device, group}});
        }
        status = zetMetricQueryCreate(pool, pool_size_ - 1, &query);
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);
        query_pool_map_.insert({query, {context, device, group}});
      }
      else {
        query = it->second.back();
        it->second.pop_back();
      }
    }

    return query;
  }
    
  void
  PutQuery(zet_metric_query_handle_t query) {
    if (query == nullptr) {
      return;
    }

    const std::lock_guard<std::mutex> lock(query_pool_mutex_);
    auto it = query_pool_map_.find(query);
    if (it == query_pool_map_.end()) {
      return;
    }
    auto it2 = free_pool_.find(it->second);
    PTI_ASSERT(it2 != free_pool_.end());
    it2->second.push_back(query);
  }

  void
  ResetQuery(zet_metric_query_handle_t query) {
    const std::lock_guard<std::mutex> lock(query_pool_mutex_);
    if (query_pool_map_.find(query) == query_pool_map_.end()) {
      return;
    }
    ze_result_t status = zetMetricQueryReset(query);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);
  }
};
 
struct ZeCommand {
  uint64_t kernel_command_id_;	//kernel or command identifier
  uint64_t instance_id_ = 0;	//unique kernel or command instance identifier
  ze_event_handle_t event_ = nullptr;
  ze_device_handle_t device_ = nullptr;
  uint64_t host_time_origin_;	// in ns
  uint64_t device_timer_frequency_;
  uint64_t device_timer_mask_;
  uint64_t metric_timer_frequency_;
  uint64_t metric_timer_mask_;
  uint64_t append_time_ = 0;
  uint64_t submit_time_ = 0;		//in ns
  uint64_t submit_time_device_ = 0;	//in ticks
  ze_command_list_handle_t command_list_ = nullptr;
  ze_command_queue_handle_t queue_ = nullptr;
  ze_fence_handle_t fence_;
  uint64_t tid_;
  uint64_t mem_size_;	// memory copy/fill size
  ZeCommandMetricQuery *command_metric_query_;
  uint32_t engine_ordinal_;
  uint32_t engine_index_;
  ZeKernelGroupSize group_size_;
  ze_group_count_t group_count_;
  ZeKernelCommandType type_;	
  bool implicit_scaling_;
  bool immediate_;
};

struct ZeKernelProfileTimestamps {
  uint64_t metric_start;
  uint64_t metric_end;
  uint64_t device_start;
  uint64_t device_end;
  int32_t subdevice_id;
};

struct ZeCommandQueue {
  ze_command_queue_handle_t queue_;
  ze_context_handle_t context_;
  ze_device_handle_t device_;
  uint32_t engine_ordinal_;
  uint32_t engine_index_;
};

struct ZeCommandList {
  ze_command_list_handle_t cmdlist_;
  ze_context_handle_t context_;
  ze_device_handle_t device_;
  uint64_t host_time_origin_;	// in ns
  uint64_t device_timer_frequency_;
  uint64_t device_timer_mask_;
  uint64_t metric_timer_frequency_;
  uint64_t metric_timer_mask_;
  uint32_t engine_ordinal_;	// valid if immediate command list
  uint32_t engine_index_;	// valid if immediate command list
  bool immediate_;
  bool implicit_scaling_;
  std::vector<ZeCommand *> commands_;	// if non-immediate command list
  std::vector<ZeCommandMetricQuery *> metric_queries_;	// if non-immediate command list
};

struct ZeKernelCommandProperties {
  uint64_t id_;		// unique identidier
  uint64_t size_;	// kernel binary size
  uint64_t base_addr_;	// kernel base address
  ze_device_handle_t device_;
  int32_t device_id_;
  uint32_t simd_width_;	// SIMD
  uint32_t nargs_;	// number of kernel arguments
  uint32_t nsubgrps_;	// maximal number of subgroups
  uint32_t slmsize_;	// SLM size
  uint32_t private_mem_size_;	// private memory size for each thread
  uint32_t spill_mem_size_;	// spill memory size for each thread
  ZeKernelGroupSize group_size_;	// group size
  ZeKernelCommandType type_;
  uint32_t regsize_;	// GRF size per thread
  bool aot_;		// AOT or JIT
  std::string name_;	// kernel or command name
};

struct ZeDevice {
  ze_device_handle_t device_;
  ze_device_handle_t parent_device_;
  uint64_t host_time_origin_;	// in ns
  uint64_t device_timer_frequency_;
  uint64_t device_timer_mask_;
  uint64_t metric_timer_frequency_;
  uint64_t metric_timer_mask_;
  ze_driver_handle_t driver_;
  ze_context_handle_t context_;
  zet_metric_group_handle_t metric_group_;
  int32_t id_;
  int32_t parent_id_;
  int32_t subdevice_id_;
  int32_t num_subdevices_;
  ze_pci_ext_properties_t pci_properties_;
};



struct ZeKernelProfileRecord {
  ze_device_handle_t device_ = nullptr;
  std::vector<ZeKernelProfileTimestamps> timestamps_;
  uint64_t kernel_command_id_;
  uint64_t instance_id_;
  ze_group_count_t group_count_;
  size_t mem_size_;
  std::vector<uint8_t> *metrics_ = nullptr;
};

enum ZeDeviceCommandHandle {
  MemoryCopy = 0,
  MemoryCopyH2H = MemoryCopy,
  MemoryCopyH2D,
  MemoryCopyH2M,
  MemoryCopyH2S,
  MemoryCopyD2H,
  MemoryCopyD2D,
  MemoryCopyD2M,
  MemoryCopyD2S,
  MemoryCopyM2H,
  MemoryCopyM2D,
  MemoryCopyM2M,
  MemoryCopyM2S,
  MemoryCopyS2H,
  MemoryCopyS2D,
  MemoryCopyS2M,
  MemoryCopyS2S,
  MemoryCopyRegion,
  MemoryCopyRegionH2H = MemoryCopyRegion,
  MemoryCopyRegionH2D,
  MemoryCopyRegionH2M,
  MemoryCopyRegionH2S,
  MemoryCopyRegionD2H,
  MemoryCopyRegionD2D,
  MemoryCopyRegionD2M,
  MemoryCopyRegionD2S,
  MemoryCopyRegionM2H,
  MemoryCopyRegionM2D,
  MemoryCopyRegionM2M,
  MemoryCopyRegionM2S,
  MemoryCopyRegionS2H,
  MemoryCopyRegionS2D,
  MemoryCopyRegionS2M,
  MemoryCopyRegionS2S,
  MemoryCopyFromContext,
  MemoryCopyFromContextH2H = MemoryCopyFromContext,
  MemoryCopyFromContextH2D,
  MemoryCopyFromContextH2M,
  MemoryCopyFromContextH2S,
  MemoryCopyFromContextD2H,
  MemoryCopyFromContextD2D,
  MemoryCopyFromContextD2M,
  MemoryCopyFromContextD2S,
  MemoryCopyFromContextM2H,
  MemoryCopyFromContextM2D,
  MemoryCopyFromContextM2M,
  MemoryCopyFromContextM2S,
  MemoryCopyFromContextS2H,
  MemoryCopyFromContextS2D,
  MemoryCopyFromContextS2M,
  MemoryCopyFromContextS2S,
  ImageCopy,
  ImageCopyH2H = ImageCopy,
  ImageCopyH2D,
  ImageCopyH2M,
  ImageCopyH2S,
  ImageCopyD2H,
  ImageCopyD2D,
  ImageCopyD2M,
  ImageCopyD2S,
  ImageCopyM2H,
  ImageCopyM2D,
  ImageCopyM2M,
  ImageCopyM2S,
  ImageCopyS2H,
  ImageCopyS2D,
  ImageCopyS2M,
  ImageCopyS2S,
  ImageCopyRegion,
  ImageCopyRegionH2H = ImageCopyRegion,
  ImageCopyRegionH2D,
  ImageCopyRegionH2M,
  ImageCopyRegionH2S,
  ImageCopyRegionD2H,
  ImageCopyRegionD2D,
  ImageCopyRegionD2M,
  ImageCopyRegionD2S,
  ImageCopyRegionM2H,
  ImageCopyRegionM2D,
  ImageCopyRegionM2M,
  ImageCopyRegionM2S,
  ImageCopyRegionS2H,
  ImageCopyRegionS2D,
  ImageCopyRegionS2M,
  ImageCopyRegionS2S,
  ImageCopyFromMemory,
  ImageCopyFromMemoryH2H = ImageCopyFromMemory,
  ImageCopyFromMemoryH2D,
  ImageCopyFromMemoryH2M,
  ImageCopyFromMemoryH2S,
  ImageCopyFromMemoryD2H,
  ImageCopyFromMemoryD2D,
  ImageCopyFromMemoryD2M,
  ImageCopyFromMemoryD2S,
  ImageCopyFromMemoryM2H,
  ImageCopyFromMemoryM2D,
  ImageCopyFromMemoryM2M,
  ImageCopyFromMemoryM2S,
  ImageCopyFromMemoryS2H,
  ImageCopyFromMemoryS2D,
  ImageCopyFromMemoryS2M,
  ImageCopyFromMemoryS2S,
  ImageCopyToMemory,
  ImageCopyToMemoryH2H = ImageCopyToMemory,
  ImageCopyToMemoryH2D,
  ImageCopyToMemoryH2M,
  ImageCopyToMemoryH2S,
  ImageCopyToMemoryD2H,
  ImageCopyToMemoryD2D,
  ImageCopyToMemoryD2M,
  ImageCopyToMemoryD2S,
  ImageCopyToMemoryM2H,
  ImageCopyToMemoryM2D,
  ImageCopyToMemoryM2M,
  ImageCopyToMemoryM2S,
  ImageCopyToMemoryS2H,
  ImageCopyToMemoryS2D,
  ImageCopyToMemoryS2M,
  ImageCopyToMemoryS2S,
  MemoryFill,
  MemoryFillH = MemoryFill,
  MemoryFillD,
  MemoryFillM,
  MemoryFillS,
  Barrier,
  MemoryRangesBarrier,
  LastCommand = MemoryRangesBarrier
};

static const char *device_command_names[] = {
  "zeCommandListAppendMemoryCopy(H2H)",
  "zeCommandListAppendMemoryCopy(H2D)",
  "zeCommandListAppendMemoryCopy(H2M)",
  "zeCommandListAppendMemoryCopy(H2S)",
  "zeCommandListAppendMemoryCopy(D2H)",
  "zeCommandListAppendMemoryCopy(D2D)",
  "zeCommandListAppendMemoryCopy(D2M)",
  "zeCommandListAppendMemoryCopy(D2S)",
  "zeCommandListAppendMemoryCopy(M2H)",
  "zeCommandListAppendMemoryCopy(M2D)",
  "zeCommandListAppendMemoryCopy(M2M)",
  "zeCommandListAppendMemoryCopy(M2S)",
  "zeCommandListAppendMemoryCopy(S2H)",
  "zeCommandListAppendMemoryCopy(S2D)",
  "zeCommandListAppendMemoryCopy(S2M)",
  "zeCommandListAppendMemoryCopy(S2S)",
  "zeCommandListAppendMemoryCopyRegion(H2H)",
  "zeCommandListAppendMemoryCopyRegion(H2D)",
  "zeCommandListAppendMemoryCopyRegion(H2M)",
  "zeCommandListAppendMemoryCopyRegion(H2S)",
  "zeCommandListAppendMemoryCopyRegion(D2H)",
  "zeCommandListAppendMemoryCopyRegion(D2D)",
  "zeCommandListAppendMemoryCopyRegion(D2M)",
  "zeCommandListAppendMemoryCopyRegion(D2S)",
  "zeCommandListAppendMemoryCopyRegion(M2H)",
  "zeCommandListAppendMemoryCopyRegion(M2D)",
  "zeCommandListAppendMemoryCopyRegion(M2M)",
  "zeCommandListAppendMemoryCopyRegion(M2S)",
  "zeCommandListAppendMemoryCopyRegion(S2H)",
  "zeCommandListAppendMemoryCopyRegion(S2D)",
  "zeCommandListAppendMemoryCopyRegion(S2M)",
  "zeCommandListAppendMemoryCopyRegion(S2S)",
  "zeCommandListAppendMemoryCopyFromContext(H2H)",
  "zeCommandListAppendMemoryCopyFromContext(H2D)",
  "zeCommandListAppendMemoryCopyFromContext(H2M)",
  "zeCommandListAppendMemoryCopyFromContext(H2S)",
  "zeCommandListAppendMemoryCopyFromContext(D2H)",
  "zeCommandListAppendMemoryCopyFromContext(D2D)",
  "zeCommandListAppendMemoryCopyFromContext(D2M)",
  "zeCommandListAppendMemoryCopyFromContext(D2S)",
  "zeCommandListAppendMemoryCopyFromContext(M2H)",
  "zeCommandListAppendMemoryCopyFromContext(M2D)",
  "zeCommandListAppendMemoryCopyFromContext(M2M)",
  "zeCommandListAppendMemoryCopyFromContext(M2S)",
  "zeCommandListAppendMemoryCopyFromContext(S2H)",
  "zeCommandListAppendMemoryCopyFromContext(S2D)",
  "zeCommandListAppendMemoryCopyFromContext(S2M)",
  "zeCommandListAppendMemoryCopyFromContext(S2S)",
  "zeCommandListAppendImageCopy(H2H)",
  "zeCommandListAppendImageCopy(H2D)",
  "zeCommandListAppendImageCopy(H2M)",
  "zeCommandListAppendImageCopy(H2S)",
  "zeCommandListAppendImageCopy(D2H)",
  "zeCommandListAppendImageCopy(D2D)",
  "zeCommandListAppendImageCopy(D2M)",
  "zeCommandListAppendImageCopy(D2S)",
  "zeCommandListAppendImageCopy(M2H)",
  "zeCommandListAppendImageCopy(M2D)",
  "zeCommandListAppendImageCopy(M2M)",
  "zeCommandListAppendImageCopy(M2S)",
  "zeCommandListAppendImageCopy(S2H)",
  "zeCommandListAppendImageCopy(S2D)",
  "zeCommandListAppendImageCopy(S2M)",
  "zeCommandListAppendImageCopy(S2S)",
  "zeCommandListAppendImageCopyRegion(H2H)",
  "zeCommandListAppendImageCopyRegion(H2D)",
  "zeCommandListAppendImageCopyRegion(H2M)",
  "zeCommandListAppendImageCopyRegion(H2S)",
  "zeCommandListAppendImageCopyRegion(D2H)",
  "zeCommandListAppendImageCopyRegion(D2D)",
  "zeCommandListAppendImageCopyRegion(D2M)",
  "zeCommandListAppendImageCopyRegion(D2S)",
  "zeCommandListAppendImageCopyRegion(M2H)",
  "zeCommandListAppendImageCopyRegion(M2D)",
  "zeCommandListAppendImageCopyRegion(M2M)",
  "zeCommandListAppendImageCopyRegion(M2S)",
  "zeCommandListAppendImageCopyRegion(S2H)",
  "zeCommandListAppendImageCopyRegion(S2D)",
  "zeCommandListAppendImageCopyRegion(S2M)",
  "zeCommandListAppendImageCopyRegion(S2S)",
  "zeCommandListAppendImageCopyFromMemory(H2H)",
  "zeCommandListAppendImageCopyFromMemory(H2D)",
  "zeCommandListAppendImageCopyFromMemory(H2M)",
  "zeCommandListAppendImageCopyFromMemory(H2S)",
  "zeCommandListAppendImageCopyFromMemory(D2H)",
  "zeCommandListAppendImageCopyFromMemory(D2D)",
  "zeCommandListAppendImageCopyFromMemory(D2M)",
  "zeCommandListAppendImageCopyFromMemory(D2S)",
  "zeCommandListAppendImageCopyFromMemory(M2H)",
  "zeCommandListAppendImageCopyFromMemory(M2D)",
  "zeCommandListAppendImageCopyFromMemory(M2M)",
  "zeCommandListAppendImageCopyFromMemory(M2S)",
  "zeCommandListAppendImageCopyFromMemory(S2H)",
  "zeCommandListAppendImageCopyFromMemory(S2D)",
  "zeCommandListAppendImageCopyFromMemory(S2M)",
  "zeCommandListAppendImageCopyFromMemory(S2S)",
  "zeCommandListAppendImageCopyToMemory(H2H)",
  "zeCommandListAppendImageCopyToMemory(H2D)",
  "zeCommandListAppendImageCopyToMemory(H2M)",
  "zeCommandListAppendImageCopyToMemory(H2S)",
  "zeCommandListAppendImageCopyToMemory(D2H)",
  "zeCommandListAppendImageCopyToMemory(D2D)",
  "zeCommandListAppendImageCopyToMemory(D2M)",
  "zeCommandListAppendImageCopyToMemory(D2S)",
  "zeCommandListAppendImageCopyToMemory(M2H)",
  "zeCommandListAppendImageCopyToMemory(M2D)",
  "zeCommandListAppendImageCopyToMemory(M2M)",
  "zeCommandListAppendImageCopyToMemory(M2S)",
  "zeCommandListAppendImageCopyToMemory(S2H)",
  "zeCommandListAppendImageCopyToMemory(S2D)",
  "zeCommandListAppendImageCopyToMemory(S2M)",
  "zeCommandListAppendImageCopyToMemory(S2S)",
  "zeCommandListAppendMemoryFill(H)",
  "zeCommandListAppendMemoryFill(D)",
  "zeCommandListAppendMemoryFill(M)",
  "zeCommandListAppendMemoryFill(S)",
  "zeCommandListAppendBarrier", 
  "zeCommandListAppendMemoryRangesBarrier" 
};


typedef void (*OnZeFunctionFinishCallback)(std::vector<uint64_t> *kids, FLOW_DIR flow_dir, API_TRACING_ID api_id, uint64_t started, uint64_t ended);

typedef void (*OnZeKernelFinishCallback)(uint64_t kid, uint64_t tid, uint64_t start, uint64_t end, uint32_t ordinal, uint32_t index, int32_t tile, const ze_device_handle_t device, const uint64_t kernel_command_id, bool implicit_scaling, const ze_group_count_t& group_count, size_t mem_size);

ze_result_t (*zexKernelGetBaseAddress)(ze_kernel_handle_t hKernel, uint64_t *baseAddress) = nullptr;

static std::shared_mutex kernel_command_properties_mutex_;
using ZeKernelProfiles = std::map<uint64_t, ZeKernelProfileRecord>;
static std::map<uint64_t, ZeKernelCommandProperties> *kernel_command_properties_ = nullptr;

static std::mutex global_kernel_profiles_mutex_;
static ZeKernelProfiles global_kernel_profiles_;
static std::map<ze_device_handle_t, ZeDevice> *devices_;

void SweepKernelProfiles(ZeKernelProfiles& profiles) {
  const std::lock_guard<std::mutex> lock(global_kernel_profiles_mutex_);
  global_kernel_profiles_.insert(profiles.begin(), profiles.end());
}

struct ZeDeviceSubmissions;
std::shared_mutex global_device_submissions_mutex_;
std::set<ZeDeviceSubmissions *> *global_device_submissions_ = nullptr;

struct ZeDeviceSubmissions {
  std::list<ZeCommand *> commands_submitted_;
  std::list<ZeCommand *> commands_staged_;
  std::list<ZeCommand *> commands_free_pool_;
  std::list<ZeCommandMetricQuery *> metric_queries_submitted_;
  std::list<ZeCommandMetricQuery *> metric_queries_staged_;
  std::list<ZeCommandMetricQuery *> metric_queries_free_pool_;
  std::map<ZeKernelCommandNameKey, ZeKernelCommandTime, ZeKernelCommandNameKeyCompare> device_time_stats_;
  std::map<uint32_t, ZeFunctionTime> host_time_stats_;
  ZeKernelProfiles kernel_profiles_;
  std::atomic<bool> finalized_;

  ZeDeviceSubmissions() {
    finalized_.store(false, std::memory_order_release);

    ZeCommand *command = new ZeCommand;

    UniMemory::ExitIfOutOfMemory((void *)(command));
    
    commands_free_pool_.push_back(command);
    global_device_submissions_mutex_.lock();
    if (global_device_submissions_ == nullptr) {
      global_device_submissions_ = new std::set<ZeDeviceSubmissions *>;
      UniMemory::ExitIfOutOfMemory((void *)(global_device_submissions_));
    }

    global_device_submissions_->insert(this);
    global_device_submissions_mutex_.unlock();
  }

  ~ZeDeviceSubmissions() {
    global_device_submissions_mutex_.lock();
    if (!finalized_.exchange(true)) {
      // finalize if not finalized
      SweepKernelCommandTimeStats(device_time_stats_);
      SweepHostFunctionTimeStats(host_time_stats_);
      SweepKernelProfiles(kernel_profiles_);
      global_device_submissions_->erase(this);
    }
    global_device_submissions_mutex_.unlock();
  }
  
  ZeDeviceSubmissions(const struct ZeDeviceSubmissions& that) = delete;

  ZeDeviceSubmissions& operator=(const struct ZeDeviceSubmissions& that) = delete;

  inline void SubmitKernelCommand(ZeCommand *command) {
    if (!IsFinalized()) {
      commands_submitted_.push_back(command);
    }
    else {
      commands_free_pool_.push_back(command);
    }
  }
  
  inline void StageKernelCommand(ZeCommand *command) {
    commands_staged_.push_back(command);
  }
  
  inline ZeCommand *GetKernelCommand(void) {
    ZeCommand *command;

    if (commands_free_pool_.empty()) {
      command = new ZeCommand;
      UniMemory::ExitIfOutOfMemory((void *)(command));
    }
    else {
      command = commands_free_pool_.front();
      commands_free_pool_.pop_front();
    }

    return command;
  }

  inline void SubmitCommandMetricQuery(ZeCommandMetricQuery *query) {
    if (!IsFinalized()) {
      metric_queries_submitted_.push_back(query);
    }
    else {
      metric_queries_free_pool_.push_back(query);
    }
  }
  
  inline void StageCommandMetricQuery(ZeCommandMetricQuery *query) {
    metric_queries_staged_.push_back(query);
  }

  inline void SubmitStagedKernelCommandAndMetricQueries(ZeEventCache& event_cache, std::vector<uint64_t> *kids) {
    auto cit = commands_staged_.begin();
    auto mit = metric_queries_staged_.begin();
    for (; cit != commands_staged_.end(); cit++, mit++) {
      ZeCommand *cmd = *cit;
      ZeCommandMetricQuery *cmd_query = *mit;

      // back fill kernel instance id and reset event    
      cmd->instance_id_ = UniKernelInstanceId::GetKernelInstanceId();
      event_cache.ResetEvent(cmd->event_);

      if (kids) {
        kids->push_back(cmd->instance_id_);
      }
      SubmitKernelCommand(cmd);

      if (cmd_query != nullptr) {
        cmd_query->instance_id_ = cmd->instance_id_;
        event_cache.ResetEvent(cmd_query->metric_query_event_);
        SubmitCommandMetricQuery(cmd_query);
      }
    }
    commands_staged_.clear();
    metric_queries_staged_.clear();
  }

  inline void RevertStagedKernelCommandAndMetricQueries(void) {
    auto cit = commands_staged_.begin();
    auto mit = metric_queries_staged_.begin();
    for (; cit != commands_staged_.end(); cit++, mit++) {
      ZeCommand *cmd = *cit;
      ZeCommandMetricQuery *cmd_query = *mit;

      commands_free_pool_.push_back(cmd);
      if (cmd_query != nullptr) {
        metric_queries_free_pool_.push_back(cmd_query);
      }
    }
    commands_staged_.clear();
    metric_queries_staged_.clear();
  }

  inline ZeCommandMetricQuery *GetCommandMetricQuery(void) {
    ZeCommandMetricQuery *query;

    if (metric_queries_free_pool_.empty()) {
      query = new ZeCommandMetricQuery;
      UniMemory::ExitIfOutOfMemory((void *)(query));
    }
    else {
      query = metric_queries_free_pool_.front();
      metric_queries_free_pool_.pop_front();
    }

    return query;
  }

  inline void CollectHostFunctionTimeStats(uint32_t id, uint64_t host_time) {
    auto it = host_time_stats_.find(id);
    if (it == host_time_stats_.end()){
      ZeFunctionTime stat;
      stat.total_time_ = host_time;
      stat.min_time_ = host_time;
      stat.max_time_ = host_time;
      stat.call_count_ = 1;
      host_time_stats_.insert({id, std::move(stat)});
    }
    else {
      it->second.total_time_ += host_time;
      if (host_time > it->second.max_time_) {
        it->second.max_time_ = host_time;
      }
      if (host_time < it->second.min_time_) {
        it->second.min_time_ = host_time;
      }
      it->second.call_count_ += 1;
    }
  }

  inline void CollectKernelCommandTimeStats(const ZeCommand *command, uint64_t kernel_start, uint64_t kernel_end, int tile) {
    ZeKernelCommandNameKey key {command->kernel_command_id_, command->mem_size_, tile, command->group_count_};
    uint64_t kernel_time = kernel_end - kernel_start;
    auto it = device_time_stats_.find(key);
    if (it == device_time_stats_.end()){
      ZeKernelCommandTime stat;
      stat.append_time_ = command->submit_time_ - command->append_time_;
      stat.submit_time_ = kernel_start - command->submit_time_;
      stat.execute_time_ = kernel_time;
      stat.min_time_ = kernel_time;
      stat.max_time_ = kernel_time;
      stat.call_count_ = 1;
      device_time_stats_.insert({std::move(key), std::move(stat)});
    }
    else {
      it->second.append_time_ += (command->submit_time_ - command->append_time_);
      it->second.submit_time_ +=  (kernel_start - command->submit_time_);
      it->second.execute_time_ += kernel_time;
      if (kernel_time > it->second.max_time_) {
        it->second.max_time_ = kernel_time;
      }
      if (kernel_time < it->second.min_time_) {
        it->second.min_time_ = kernel_time;
      }
      it->second.call_count_ += 1;
    }
  }

  inline bool IsFinalized(void) {
    return finalized_.load(std::memory_order_acquire);
  }

  inline void Finalize(void) {
    // caller holds exclusive global_device_submissions_mutex_ lock
    finalized_.store(true, std::memory_order_release);
    SweepKernelCommandTimeStats(device_time_stats_);
    SweepHostFunctionTimeStats(host_time_stats_);
    SweepKernelProfiles(kernel_profiles_);
  }
};


static std::shared_mutex devices_mutex_;
static std::map<uint64_t, ZeKernelCommandProperties> *active_command_properties_ = nullptr;

static std::map<ze_kernel_handle_t, ZeKernelCommandProperties> *active_kernel_properties_ = nullptr;

thread_local ZeDeviceSubmissions local_device_submissions_;

inline std::string GetZeKernelCommandName(uint64_t id, const ze_group_count_t& group_count, size_t size, bool detailed = true) {
  std::string str;
  kernel_command_properties_mutex_.lock_shared();
  auto it = kernel_command_properties_->find(id);
  if (it != kernel_command_properties_->end()) {
    str = "\"" + std::move(utils::Demangle(it->second.name_.c_str()));	// quote kernel name which may contain ","
    if (detailed) {
      if (it->second.type_ == KERNEL_COMMAND_TYPE_COMPUTE) {
        if (it->second.simd_width_ > 0) {
          str += "[SIMD";
          if (it->second.simd_width_ == 1) {
            str += "_ANY";
          } else {
            str += std::to_string(it->second.simd_width_);
          }
        }
        str = str + " {" +
          std::to_string(group_count.groupCountX) + "; " +
          std::to_string(group_count.groupCountY) + "; " +
          std::to_string(group_count.groupCountZ) + "} {" +
          std::to_string(it->second.group_size_.x) + "; " +
          std::to_string(it->second.group_size_.y) + "; " +
          std::to_string(it->second.group_size_.z) + "}]";
      }
      else if ((it->second.type_ == KERNEL_COMMAND_TYPE_MEMORY) && (size > 0)) {
        str = str + "[" + std::to_string(size) + "]";
      }
    }
    str += "\"";	// quoate kernel name
  }

  kernel_command_properties_mutex_.unlock_shared();

  return str;
}

inline std::string GetZeKernelCommandName(uint64_t id, ze_group_count_t& group_count, size_t size, bool detailed = true) {
  const ze_group_count_t& gcount = group_count;
  return GetZeKernelCommandName(id, gcount, size, detailed);
}


class ZeCollector {
 public: // Interface

  static ZeCollector* Create(
      Correlator* correlator,
      CollectorOptions options,
      OnZeKernelFinishCallback kcallback = nullptr,
      OnZeFunctionFinishCallback fcallback = nullptr,
      void* callback_data = nullptr) {
    ze_api_version_t version = utils::ze::GetVersion();
    PTI_ASSERT(
        ZE_MAJOR_VERSION(version) >= 1 &&
        ZE_MINOR_VERSION(version) >= 2);

    PTI_ASSERT(correlator != nullptr);

    std::string data_dir_name = utils::GetEnv("UNITRACE_DataDir");
    ZeCollector* collector = new ZeCollector(
        correlator, options, kcallback, fcallback, callback_data, data_dir_name);

    UniMemory::ExitIfOutOfMemory((void *)(collector));

    ze_result_t status = ZE_RESULT_SUCCESS;
    zel_tracer_desc_t tracer_desc = {
        ZEL_STRUCTURE_TYPE_TRACER_EXP_DESC, nullptr, collector};
    zel_tracer_handle_t tracer = nullptr;
    status = zelTracerCreate(&tracer_desc, &tracer);
    if (status != ZE_RESULT_SUCCESS) {
      std::cerr << "[WARNING] Unable to create Level Zero tracer" << std::endl;
      delete collector;
      return nullptr;
    }

    collector->EnableTracing(tracer);

    collector->tracer_ = tracer;
    
    ze_driver_handle_t driver;
    uint32_t count = 1;
    if (zeDriverGet(&count, &driver) == ZE_RESULT_SUCCESS) {
      if (zeDriverGetExtensionFunctionAddress(driver, "zexKernelGetBaseAddress", (void **)&zexKernelGetBaseAddress) != ZE_RESULT_SUCCESS) {
        zexKernelGetBaseAddress = nullptr;
      }
    }

    return collector;
  }

  ZeCollector(const ZeCollector& that) = delete;

  ZeCollector& operator=(const ZeCollector& that) = delete;

  ~ZeCollector() {
    
    ProcessAllCommandsSubmitted(nullptr);

    if (tracer_ != nullptr) {
      ze_result_t status = zelTracerDestroy(tracer_);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    }

    global_device_submissions_mutex_.lock();
    if (global_device_submissions_) {
      for (auto it = global_device_submissions_->begin(); it != global_device_submissions_->end();) {
        (*it)->Finalize();
        it = global_device_submissions_->erase(it);
      }
    }
    global_device_submissions_mutex_.unlock();

    if (options_.metric_query) {
      for (auto it = metric_activations_.begin(); it != metric_activations_.end(); it++) {
        zetContextActivateMetricGroups(it->first, it->second, 0, nullptr);
      }
      metric_activations_.clear();
      for (auto& context : metric_contexts_) {
        zeContextDestroy(context);
      }
      metric_contexts_.clear();
    }

    DumpKernelProfiles();
  }
  
  void DisableTracing() {
    ze_result_t status = zelTracerSetEnabled(tracer_, false);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);
  }

  void ProcessAllCommandsSubmitted(std::vector<uint64_t> *kids) {
    if (local_device_submissions_.IsFinalized()) {
      return;
    }
    ze_result_t status = ZE_RESULT_SUCCESS;

    global_device_submissions_mutex_.lock();
    if (global_device_submissions_) {
      for (auto s : *global_device_submissions_) {
        auto& local_device_submissions = *s;
        auto it = local_device_submissions.commands_submitted_.begin();
        while (it != local_device_submissions.commands_submitted_.end()) {
          ZeCommand *command = *it;
    
          if (command->event_ != nullptr) {
            status = zeEventQueryStatus(command->event_);
            if (status == ZE_RESULT_SUCCESS) {
              ProcessCommandSubmitted(local_device_submissions, command, kids);
              local_device_submissions_.commands_free_pool_.push_back(command);
              it = local_device_submissions.commands_submitted_.erase(it);
              continue;
            }
          }
          ++it;
        }
        if (options_.metric_query) {
          ProcessCommandMetricQueriesSubmitted();
        }
      }
    }
    global_device_submissions_mutex_.unlock();
  }


 private: // Implementation

  ZeCollector(
      Correlator* correlator,
      CollectorOptions options,
      OnZeKernelFinishCallback kcallback,
      OnZeFunctionFinishCallback fcallback,
      void* callback_data,
      std::string& data_dir_name)
      : correlator_(correlator),
        options_(options),
        kcallback_(kcallback),
        fcallback_(fcallback),
        callback_data_(callback_data),
        event_cache_(ZE_EVENT_POOL_FLAG_KERNEL_TIMESTAMP) {
    data_dir_name_ = data_dir_name;
    EnumerateAndSetupDevices();
    InitializeKernelCommandProperties();
  }

  void InitializeKernelCommandProperties(void) {
    kernel_command_properties_mutex_.lock();
    if (active_command_properties_ == nullptr) {
      active_command_properties_ = new std::map<uint64_t, ZeKernelCommandProperties>;
      UniMemory::ExitIfOutOfMemory((void *)(active_command_properties_));
    }
    if (active_kernel_properties_ == nullptr) {
      active_kernel_properties_ = new std::map<ze_kernel_handle_t, ZeKernelCommandProperties>;
      UniMemory::ExitIfOutOfMemory((void *)(active_kernel_properties_));
    }
    if (kernel_command_properties_ == nullptr) {
      kernel_command_properties_ = new std::map<uint64_t, ZeKernelCommandProperties>;
      UniMemory::ExitIfOutOfMemory((void *)(kernel_command_properties_));
    }

    for (uint32_t i = 0; i <= uint32_t(ZeDeviceCommandHandle::LastCommand); i++) {
      ZeKernelCommandProperties desc;
      
      desc.name_ = device_command_names[i];
      desc.id_ = UniKernelId::GetKernelId();
      if (i <= uint32_t(ZeDeviceCommandHandle::Barrier)) {
        desc.type_ = KERNEL_COMMAND_TYPE_MEMORY;
      }
      else {
        desc.type_ = KERNEL_COMMAND_TYPE_COMMAND;
      }
      
      ZeKernelCommandProperties desc2;
      desc2 = desc;

      active_command_properties_->insert({uint64_t(i), std::move(desc)});
      kernel_command_properties_->insert({desc2.id_, std::move(desc2)});
    }
    kernel_command_properties_mutex_.unlock();
  }

  void EnumerateAndSetupDevices() {
    if (devices_ == nullptr) {
      devices_ = new std::map<ze_device_handle_t, ZeDevice>;
      UniMemory::ExitIfOutOfMemory((void *)(devices_));
    }

    ze_result_t status = ZE_RESULT_SUCCESS;
    uint32_t num_drivers = 0;
    status = zeDriverGet(&num_drivers, nullptr);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    if (num_drivers > 0) {
      int32_t did = 0;
      std::vector<ze_driver_handle_t> drivers(num_drivers);
      std::vector<ze_context_handle_t> contexts;
      status = zeDriverGet(&num_drivers, drivers.data());
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
      for (auto driver : drivers) {
        ze_context_handle_t context = nullptr;
        if (options_.metric_query) {
          ze_context_desc_t cdesc = {ZE_STRUCTURE_TYPE_CONTEXT_DESC, nullptr, 0};

          status = zeContextCreate(driver, &cdesc, &context);
          PTI_ASSERT(status == ZE_RESULT_SUCCESS);
          metric_contexts_.push_back(context);
        }

        uint32_t num_devices = 0;
        status = zeDeviceGet(driver, &num_devices, nullptr);
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);
        if (num_devices) {
          std::vector<ze_device_handle_t> devices(num_devices);
          status = zeDeviceGet(driver, &num_devices, devices.data());
          PTI_ASSERT(status == ZE_RESULT_SUCCESS);
          for (auto device : devices) {
            ZeDevice desc;
  
            desc.device_ = device;
            desc.id_ = did;
            desc.parent_id_ = -1;	// no parent
            desc.parent_device_ = nullptr;
            desc.subdevice_id_ = -1;	// not a subdevice
            desc.device_timer_frequency_ = utils::ze::GetDeviceTimerFrequency(device);
            desc.device_timer_mask_ = utils::ze::GetDeviceTimestampMask(device);
            desc.metric_timer_frequency_ = utils::ze::GetMetricTimerFrequency(device);
            desc.metric_timer_mask_ = utils::ze::GetMetricTimestampMask(device);

            ze_pci_ext_properties_t pci_device_properties;
            ze_result_t status = zeDevicePciGetPropertiesExt(device, &pci_device_properties);
            PTI_ASSERT(status == ZE_RESULT_SUCCESS);
            desc.pci_properties_ = pci_device_properties;

            desc.driver_ = driver;
            desc.context_ = context;

            uint32_t num_sub_devices = 0;
            status = zeDeviceGetSubDevices(device, &num_sub_devices, nullptr);
            PTI_ASSERT(status == ZE_RESULT_SUCCESS);

            desc.num_subdevices_ = num_sub_devices;

            if (options_.metric_query) {
              uint32_t num_groups = 0;
              zet_metric_group_handle_t group = nullptr;
              status = zetMetricGroupGet(device, &num_groups, nullptr);
              PTI_ASSERT(status == ZE_RESULT_SUCCESS);
              if (num_groups > 0) {
                std::vector<zet_metric_group_handle_t> groups(num_groups, nullptr);
                status = zetMetricGroupGet(device, &num_groups, groups.data());
                PTI_ASSERT(status == ZE_RESULT_SUCCESS);

                for (uint32_t k = 0; k < num_groups; ++k) {
                  zet_metric_group_properties_t group_props{};
                  group_props.stype = ZET_STRUCTURE_TYPE_METRIC_GROUP_PROPERTIES;
                  status = zetMetricGroupGetProperties(groups[k], &group_props);
                  PTI_ASSERT(status == ZE_RESULT_SUCCESS);

                  
                  if ((strcmp(group_props.name, utils::GetEnv("UNITRACE_MetricGroup").c_str()) == 0) && (group_props.samplingType & ZET_METRIC_GROUP_SAMPLING_TYPE_FLAG_EVENT_BASED)) {
                    group = groups[k];
                    break;
                  }
                }
              }

              status = zetContextActivateMetricGroups(context, device, 1, &group);
              PTI_ASSERT(status == ZE_RESULT_SUCCESS);
              metric_activations_.insert({context, device});

              desc.metric_group_ = group;
            }
            else {
              desc.metric_group_ = nullptr;
            }

            uint64_t host_time;
            uint64_t ticks;

            status = zeDeviceGetGlobalTimestamps(device, &host_time, &ticks);
            PTI_ASSERT(status == ZE_RESULT_SUCCESS);

            desc.host_time_origin_ = host_time;

            devices_->insert({device, std::move(desc)});

            if (num_sub_devices > 0) {
              std::vector<ze_device_handle_t> sub_devices(num_sub_devices);

              status = zeDeviceGetSubDevices(device, &num_sub_devices, sub_devices.data());
              PTI_ASSERT(status == ZE_RESULT_SUCCESS);

              for (int j = 0; j < num_sub_devices; j++) {
                ZeDevice sub_desc;
  
                sub_desc.device_ = sub_devices[j];
                sub_desc.parent_id_ = did;
                sub_desc.parent_device_ = device;
                sub_desc.num_subdevices_ = 0;
                sub_desc.subdevice_id_ = j;
                sub_desc.id_ = did;	// take parent device's id
                sub_desc.device_timer_frequency_ = utils::ze::GetDeviceTimerFrequency(sub_devices[j]);
                sub_desc.device_timer_mask_ = utils::ze::GetDeviceTimestampMask(sub_devices[j]);
                sub_desc.metric_timer_frequency_ = utils::ze::GetMetricTimerFrequency(sub_devices[j]);
                sub_desc.metric_timer_mask_ = utils::ze::GetMetricTimestampMask(sub_devices[j]);
  
                ze_pci_ext_properties_t pci_device_properties;
                ze_result_t status = zeDevicePciGetPropertiesExt(sub_devices[j], &pci_device_properties);
                PTI_ASSERT(status == ZE_RESULT_SUCCESS);
                sub_desc.pci_properties_ = pci_device_properties;
  
                uint64_t ticks;
                uint64_t host_time;
                status = zeDeviceGetGlobalTimestamps(sub_devices[j], &host_time, &ticks);
                PTI_ASSERT(status == ZE_RESULT_SUCCESS);

                sub_desc.host_time_origin_ = host_time;
  
                sub_desc.driver_ = driver;
                sub_desc.context_ = context;
            
                sub_desc.metric_group_ = nullptr;

                devices_->insert({sub_devices[j], std::move(sub_desc)});
              }
            }
            did++;
          }
        }
      }
    }
  }


  static std::string PrintTypedValue(const zet_typed_value_t& typed_value) {
    switch (typed_value.type) {
      case ZET_VALUE_TYPE_UINT32:
        return std::to_string(typed_value.value.ui32);
      case ZET_VALUE_TYPE_UINT64:
        return std::to_string(typed_value.value.ui64);
      case ZET_VALUE_TYPE_FLOAT32:
        return std::to_string(typed_value.value.fp32);
      case ZET_VALUE_TYPE_FLOAT64:
        return std::to_string(typed_value.value.fp64);
      case ZET_VALUE_TYPE_BOOL8:
        return std::to_string(static_cast<uint32_t>(typed_value.value.b8));
      default:
        PTI_ASSERT(0);
        break;
    }
  }


  inline static std::string GetMetricUnits(const char* units) {
    PTI_ASSERT(units != nullptr);

    std::string result = units;
    if (result.find("null") != std::string::npos) {
      result = "";
    } else if (result.find("percent") != std::string::npos) {
      result = "%";
    }

    return result;
  }

  static uint32_t GetMetricCount(zet_metric_group_handle_t group) {
    PTI_ASSERT(group != nullptr);

    zet_metric_group_properties_t group_props{};
    group_props.stype = ZET_STRUCTURE_TYPE_METRIC_GROUP_PROPERTIES;
    ze_result_t status = zetMetricGroupGetProperties(group, &group_props);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);

    return group_props.metricCount;
  }

  static std::vector<std::string> GetMetricNames(zet_metric_group_handle_t group) {
    PTI_ASSERT(group != nullptr);

    uint32_t metric_count = GetMetricCount(group);
    PTI_ASSERT(metric_count > 0);

    std::vector<zet_metric_handle_t> metrics(metric_count);
    ze_result_t status = zetMetricGet(group, &metric_count, metrics.data());
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    PTI_ASSERT(metric_count == metrics.size());

    std::vector<std::string> names;
    for (auto metric : metrics) {
      zet_metric_properties_t metric_props{
          ZET_STRUCTURE_TYPE_METRIC_PROPERTIES, };
      status = zetMetricGetProperties(metric, &metric_props);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);

      std::string units = GetMetricUnits(metric_props.resultUnits);
      std::string name = metric_props.name;
      if (!units.empty()) {
        name += "[" + units + "]";
      }
      names.push_back(name);
    }

    return names;
  }

  bool QueryKernelCommandMetrics(ZeDeviceSubmissions& submissions, ZeCommandMetricQuery *command_metric_query) {

    ze_result_t status;
    if ((status = zeEventQueryStatus(command_metric_query->metric_query_event_)) == ZE_RESULT_SUCCESS) {

      auto it = submissions.kernel_profiles_.find(command_metric_query->instance_id_);
      if (it != submissions.kernel_profiles_.end()) {
        size_t size = 0;
        status = zetMetricQueryGetData(command_metric_query->metric_query_, &size, nullptr);
        if ((status == ZE_RESULT_SUCCESS) && (size > 0)) {

          std::vector<uint8_t> *kmetrics = new std::vector<uint8_t>(size);
          UniMemory::ExitIfOutOfMemory((void *)(kmetrics));
          size_t size2 = size;
          status = zetMetricQueryGetData(command_metric_query->metric_query_, &size2, kmetrics->data());
          if (size2 == size) {
            it->second.metrics_ = kmetrics;
          }
          else {
            delete kmetrics;
          }
        }
      }
      event_cache_.ResetEvent(command_metric_query->metric_query_event_);
      query_pools_.ResetQuery(command_metric_query->metric_query_);
      if (command_metric_query->immediate_) {
        event_cache_.ReleaseEvent(command_metric_query->metric_query_event_);
        query_pools_.PutQuery(command_metric_query->metric_query_);
      }
      command_metric_query->metric_query_event_ = nullptr;
      command_metric_query->metric_query_ = nullptr;

      return true;
    }
    else {
      return false;
    }
  }


  void ProcessCommandMetricQueriesSubmitted(void) {
    for (auto it = local_device_submissions_.metric_queries_submitted_.begin(); it != local_device_submissions_.metric_queries_submitted_.end();) {
      if (QueryKernelCommandMetrics(local_device_submissions_, *it)) {
        local_device_submissions_.metric_queries_free_pool_.push_back(*it);
        it = local_device_submissions_.metric_queries_submitted_.erase(it);
      }
      else {
        it++;
      }
    }
  }

  void DumpKernelProfiles(void) {
    ze_device_handle_t device = nullptr;
    int did = -1;
    zet_metric_group_handle_t group = nullptr;
    std::vector<std::string> metric_names;

    if (options_.stall_sampling) {
      kernel_command_properties_mutex_.lock();
      std::map<int32_t, std::map<uint64_t, ZeKernelCommandProperties *>> device_kprops; // sorted by device id then base address;
      for (auto it = kernel_command_properties_->begin(); it != kernel_command_properties_->end(); it++) {
        if (it->second.type_ != KERNEL_COMMAND_TYPE_COMPUTE) {
          continue;
        }
        auto dkit = device_kprops.find(it->second.device_id_);
        if (dkit == device_kprops.end()) {
          std::map<uint64_t, ZeKernelCommandProperties *> kprops;
          kprops.insert({it->second.base_addr_, &(it->second)});
          device_kprops.insert({it->second.device_id_, std::move(kprops)});
        }
        else {
          if (dkit->second.find(it->second.base_addr_) != dkit->second.end()) {
            // already inserted
            continue;
          }
          dkit->second.insert({it->second.base_addr_, &(it->second)});
        }
      }

      for (auto& props : device_kprops) {
        // kernel properties file path: data_dir/.kprops.<device_id>.<pid>.txt
        std::string fpath = data_dir_name_ + "/.kprops."  + std::to_string(props.first) + "." + std::to_string(utils::GetPid()) + ".txt";
        std::ofstream kpfs = std::ofstream(fpath, std::ios::out | std::ios::trunc);
        uint64_t prev_base = 0;
        for (auto it = props.second.crbegin(); it != props.second.crend(); it++) {
          // quote kernel name which may contain "," 
          kpfs << "\"" << utils::Demangle(it->second->name_.c_str()) << "\"" << std::endl;
          kpfs << it->second->base_addr_ << std::endl;
          if (prev_base == 0) {
            kpfs << it->second->size_ << std::endl;
          }
          else {
            size_t size = prev_base - it->second->base_addr_;
            if (size > it->second->size_) {
              size = it->second->size_;
            }
            kpfs << size << std::endl;
          }
          prev_base = it->second->base_addr_;
        }
        kpfs.close();
      }

      kernel_command_properties_mutex_.unlock();
    }
    
    const std::lock_guard<std::mutex> lock(global_kernel_profiles_mutex_);
    if (global_kernel_profiles_.size() == 0) {
      return;
    }
    
    if (options_.metric_stream) {
      devices_mutex_.lock_shared();
      std::map<int32_t, std::vector<ZeKernelProfileRecord *>> device_kprofiles; // kernel profiles by device;
      for (auto it = global_kernel_profiles_.begin(); it != global_kernel_profiles_.end(); it++) {
        int32_t device_id = -1;
        auto dit = devices_->find(it->second.device_);
        if (dit != devices_->end()) {
          device_id = dit->second.id_;
        }
        if (device_id == -1) {
          continue;
        }
        auto dpit = device_kprofiles.find(device_id);
        if (dpit == device_kprofiles.end()) {
          std::vector<ZeKernelProfileRecord *> kprofiles;
          kprofiles.push_back(&(it->second));
          device_kprofiles.insert({device_id, std::move(kprofiles)});
        }
        else {
          dpit->second.push_back(&(it->second));
        }
      }
      devices_mutex_.unlock_shared();

      for (auto& profiles : device_kprofiles) {
        std::ofstream ouf;
        // kernel instance time file path: <data_dir>/.ktime.<device_id>.<pid>.txt
        std::string fpath = data_dir_name_ + "/.ktime."  + std::to_string(profiles.first) + "." + std::to_string(utils::GetPid()) + ".txt";
        ouf = std::ofstream(fpath, std::ios::out | std::ios::trunc);
        for (auto& prof : profiles.second) {
          for (auto& ts : prof->timestamps_) {
            std::string kname = GetZeKernelCommandName(prof->kernel_command_id_, prof->group_count_, prof->mem_size_);
            ouf << ts.subdevice_id << std::endl;
            ouf << ts.metric_start << std::endl;
            ouf << ts.metric_end << std::endl;
            ouf << kname << std::endl;
          }
        }
        ouf.close();
      }

      return;
    }

    if (!options_.metric_query) {
      return;
    }

    // metric query
    correlator_->Log("\n== Kernel Metrics ==\n\n");

    for (auto it = global_kernel_profiles_.begin(); it != global_kernel_profiles_.end(); it++) {
      if ((it->second.metrics_ == nullptr) || it->second.metrics_->empty()) {
        continue;
      }

      std::string kname = GetZeKernelCommandName(it->second.kernel_command_id_, it->second.group_count_, it->second.mem_size_);

      if (device != it->second.device_) {
        device = it->second.device_;
        auto it2 = devices_->find(it->second.device_);
        
        if (it2 == devices_->end()) {
          // should never get here
          continue;
        }

        did = it2->second.id_;
        group = it2->second.metric_group_;
        metric_names = GetMetricNames(it2->second.metric_group_);
        PTI_ASSERT(!metric_names.empty());
      }

      uint32_t num_samples = 0;
      uint32_t num_metrics = 0;
      ze_result_t status = zetMetricGroupCalculateMultipleMetricValuesExp(
        group, ZET_METRIC_GROUP_CALCULATION_TYPE_METRIC_VALUES,
        it->second.metrics_->size(), it->second.metrics_->data(), &num_samples, &num_metrics,
        nullptr, nullptr);

      if ((status == ZE_RESULT_SUCCESS) && (num_samples > 0) && (num_metrics > 0)) {
        std::vector<uint32_t> samples(num_samples);
        std::vector<zet_typed_value_t> metrics(num_metrics);

        status = zetMetricGroupCalculateMultipleMetricValuesExp(
          group, ZET_METRIC_GROUP_CALCULATION_TYPE_METRIC_VALUES,
          it->second.metrics_->size(), it->second.metrics_->data(), &num_samples, &num_metrics,
          samples.data(), metrics.data());

        if (status == ZE_RESULT_SUCCESS) {
          std::string header("\nKernel,Device,SubDeviceId,");
          for (auto& metric : metric_names) {
            header += metric + ",";
          }
          header += "\n";
          correlator_->Log(header);
    
          std::string str;
          for (uint32_t i = 0; i < num_samples; ++i) {
            str = kname + ",";
            str += std::to_string(did) + ",";
            str += std::to_string(i) + ",";
    
            uint32_t size = samples[i];
            PTI_ASSERT(size == metric_names.size());
    
            const zet_typed_value_t *value = metrics.data() + i * size;
            for (int j = 0; j < size; ++j) {
              str += PrintTypedValue(value[j]);
              str += ",";
            }
            str += "\n";
          }
    
          correlator_->Log(str);
        }
        else {
          std::cerr << "[WARNING] Not able to calculate metrics" << std::endl;
        }
      }
      else {
        std::cerr << "[WARNING] Not able to calculate metrics" << std::endl;
      }
    }

    global_kernel_profiles_.clear();
  }

  inline void ProcessCommandSubmitted(ZeDeviceSubmissions& submissions, ZeCommand *command, std::vector<uint64_t> *kids) {

    if (kids) {
        kids->push_back(command->instance_id_);
    }

    ze_kernel_timestamp_result_t timestamp{};
    ze_result_t status = zeEventQueryKernelTimestamp(command->event_, &timestamp);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);

    uint64_t device_freq = command->device_timer_frequency_;
    uint64_t device_mask = command->device_timer_mask_;

    uint64_t metric_freq = command->metric_timer_frequency_;
    uint64_t metric_mask = command->metric_timer_mask_;

    ZeKernelProfileRecord r;
    
    if (options_.metric_query || options_.metric_stream) {
      r.device_ = command->device_;
      r.instance_id_ = command->instance_id_;
      r.kernel_command_id_ = command->kernel_command_id_;
      r.group_count_ = command->group_count_;
      r.mem_size_ = command->mem_size_;
    }
      

    if (options_.kernels_per_tile && (command->type_ == KERNEL_COMMAND_TYPE_COMPUTE)) {
      if (command->implicit_scaling_) { // Implicit Scaling
        uint32_t count = 0;
        ze_result_t status = zeEventQueryTimestampsExp(command->event_, command->device_, &count, nullptr);
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);
        PTI_ASSERT(count > 0);

        std::vector<ze_kernel_timestamp_result_t> timestamps(count);
        status = zeEventQueryTimestampsExp(command->event_, command->device_, &count, timestamps.data());
        PTI_ASSERT(status == ZE_RESULT_SUCCESS);

        if (options_.metric_query || options_.metric_stream) {
          for (int i = 0; i < count; i++) {
            ZeKernelProfileTimestamps ts;

            ts.subdevice_id = i;
            
            ts.device_start = timestamps[i].global.kernelStart & device_mask;
            ts.device_start = (ts.device_start * NSEC_IN_SEC / device_freq);
  
            ts.metric_start = timestamps[i].global.kernelStart & metric_mask;
            ts.metric_start = (ts.metric_start * NSEC_IN_SEC / metric_freq);
            
            ts.device_end = timestamps[i].global.kernelEnd & device_mask;
            ts.device_end = (ts.device_end * NSEC_IN_SEC / device_freq);
  
            ts.metric_end = timestamps[i].global.kernelEnd & metric_mask;
            ts.metric_end = (ts.metric_end * NSEC_IN_SEC / metric_freq);
      
            r.timestamps_.push_back(std::move(ts));
          }
          
          submissions.kernel_profiles_.insert({command->instance_id_, std::move(r)});
        }

      } else { // Explicit Scaling
        auto it = devices_->find(command->device_);

        if (options_.metric_query || options_.metric_stream) {
          ZeKernelProfileTimestamps ts;

          ts.device_start = timestamp.global.kernelStart & device_mask;
          ts.device_start = (ts.device_start * NSEC_IN_SEC / device_freq);
  
          ts.metric_start = timestamp.global.kernelStart & metric_mask;
          ts.metric_start = (ts.metric_start * NSEC_IN_SEC / metric_freq);
            
          ts.device_end = timestamp.global.kernelEnd & device_mask;
          ts.device_end = (ts.device_end * NSEC_IN_SEC / device_freq);
  
          ts.metric_end = timestamp.global.kernelEnd & metric_mask;
          ts.metric_end = (ts.metric_end * NSEC_IN_SEC / metric_freq);
  
          ts.subdevice_id = -1;
      
  
          r.timestamps_.push_back(std::move(ts));
            
          submissions.kernel_profiles_.insert({command->instance_id_, std::move(r)});
        }
      }
    } else {
      if (options_.metric_query || options_.metric_stream) {
        ZeKernelProfileTimestamps ts;

        ts.device_start = timestamp.global.kernelStart & device_mask;
        ts.device_start = (ts.device_start * NSEC_IN_SEC / device_freq);
  
        ts.metric_start = timestamp.global.kernelStart & metric_mask;
        ts.metric_start = (ts.metric_start * NSEC_IN_SEC / metric_freq);
            
        ts.device_end = timestamp.global.kernelEnd & device_mask;
        ts.device_end = (ts.device_end * NSEC_IN_SEC / device_freq);
  
        ts.metric_end = timestamp.global.kernelEnd & metric_mask;
        ts.metric_end = (ts.metric_end * NSEC_IN_SEC / metric_freq);
      
        ts.subdevice_id = -1;
        r.timestamps_.push_back(std::move(ts));
            
        submissions.kernel_profiles_.insert({command->instance_id_, std::move(r)});
      }

    }

    if (command->immediate_) {
      event_cache_.ReleaseEvent(command->event_);
    }
    else {
      event_cache_.ResetEvent(command->event_);
    }
    command->event_ = nullptr;
  }

  #include <tracing.gen> // Auto-generated callbacks

  void CollectHostFunctionTimeStats(uint32_t id, uint64_t time) {
    local_device_submissions_.CollectHostFunctionTimeStats(id, time);
  }

 private: // Data
  zel_tracer_handle_t tracer_ = nullptr;
  CollectorOptions options_;
  Correlator* correlator_ = nullptr;
  OnZeKernelFinishCallback kcallback_ = nullptr;
  OnZeFunctionFinishCallback fcallback_ = nullptr;
  void* callback_data_ = nullptr;

  mutable std::shared_mutex images_mutex_;
  std::map<ze_image_handle_t, size_t> images_;

  ZeEventCache event_cache_;
  
  mutable std::shared_mutex command_queues_mutex_;
  std::map<ze_command_queue_handle_t, ZeCommandQueue> command_queues_;

  mutable std::shared_mutex command_lists_mutex_;
  std::map<ze_command_list_handle_t, ZeCommandList *> command_lists_;

  std::set<std::pair<ze_context_handle_t, ze_device_handle_t>> metric_activations_;

  ZeMetricQueryPools query_pools_;

  std::vector<ze_context_handle_t> metric_contexts_;

  constexpr static size_t kCallsLength = 12;
  constexpr static size_t kTimeLength = 20;

  std::string data_dir_name_;
};

#endif // PTI_TOOLS_UNITRACE_LEVEL_ZERO_COLLECTOR_H_