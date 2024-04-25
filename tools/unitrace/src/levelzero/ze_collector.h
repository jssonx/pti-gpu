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

#include "utils.h" // utils
#include "ze_utils.h" // utils
#include "collector_options.h"
#include "unikernel.h"
#include "unitimer.h"
#include "unicontrol.h"
#include "unimemory.h"

#include "common_header.gen"

struct ZeInstanceData {
  uint64_t start_time_host;	// in ns
  uint64_t timestamp_host;	// in ns
  uint64_t timestamp_device;	// in ticks
  uint64_t kid;	// passing kid from enter callback to exit callback
};

thread_local ZeInstanceData ze_instance_data;

enum ZeKernelCommandType {
  KERNEL_COMMAND_TYPE_INVALID = 0,
  KERNEL_COMMAND_TYPE_COMPUTE = 1,
  KERNEL_COMMAND_TYPE_MEMORY = 2,
  KERNEL_COMMAND_TYPE_COMMAND = 3
};

static std::mutex global_kernel_profiles_mutex_;

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
  uint64_t tid_;
  uint64_t mem_size_;	// memory copy/fill size
  uint32_t engine_ordinal_;
  uint32_t engine_index_;
  ze_group_count_t group_count_;
  ZeKernelCommandType type_;	
  bool implicit_scaling_;
  bool immediate_;
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
  ZeKernelCommandType type_;
  uint32_t regsize_;	// GRF size per thread
  bool aot_;		// AOT or JIT
  std::string name_;	// kernel or command name
};

// these will not go away when ZeCollector is destructed
static std::shared_mutex kernel_command_properties_mutex_;
static std::map<uint64_t, ZeKernelCommandProperties> *kernel_command_properties_ = nullptr;
static std::map<ze_kernel_handle_t, ZeKernelCommandProperties> *active_kernel_properties_ = nullptr;

struct ZeModule {
  ze_device_handle_t device_;
  size_t size_;
  bool aot_;	// AOT or JIT
};

static std::shared_mutex modules_on_devices_mutex_;
static std::map<ze_module_handle_t, ZeModule> modules_on_devices_; //module to ZeModule map

struct ZeDevice {
  ze_device_handle_t device_;
  ze_device_handle_t parent_device_;
  uint64_t host_time_origin_;	// in ns
  uint64_t device_timer_frequency_;
  uint64_t device_timer_mask_;
  uint64_t metric_timer_frequency_;
  uint64_t metric_timer_mask_;
  ze_driver_handle_t driver_;
  zet_metric_group_handle_t metric_group_;
  int32_t id_;
  int32_t parent_id_;
  int32_t subdevice_id_;
  int32_t num_subdevices_;
  ze_pci_ext_properties_t pci_properties_;
};

// these will no go away when ZeCollector is destructed
static std::shared_mutex devices_mutex_;
static std::map<ze_device_handle_t, ZeDevice> *devices_;

ze_result_t (*zexKernelGetBaseAddress)(ze_kernel_handle_t hKernel, uint64_t *baseAddress) = nullptr; // TODO

class ZeCollector {
 public: // Interface

  static ZeCollector* Create(
      CollectorOptions options) {
    ze_api_version_t version = utils::ze::GetVersion();
    PTI_ASSERT(
        ZE_MAJOR_VERSION(version) >= 1 &&
        ZE_MINOR_VERSION(version) >= 2);

    std::string data_dir_name = utils::GetEnv("UNITRACE_DataDir");
    ZeCollector* collector = new ZeCollector(
        options, data_dir_name);

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

    if (tracer_ != nullptr) {
      ze_result_t status = zelTracerDestroy(tracer_);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
    }

    DumpKernelProfiles();
  }

  void DisableTracing() {
    ze_result_t status = zelTracerSetEnabled(tracer_, false);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);
  }

 private: // Implementation

  ZeCollector(
      CollectorOptions options,
      std::string& data_dir_name)
      : options_(options) {
    data_dir_name_ = data_dir_name;
    EnumerateAndSetupDevices();
    InitializeKernelCommandProperties();
  }

  void InitializeKernelCommandProperties(void) { // TODO
    kernel_command_properties_mutex_.lock();
    if (active_kernel_properties_ == nullptr) {
      active_kernel_properties_ = new std::map<ze_kernel_handle_t, ZeKernelCommandProperties>;
      UniMemory::ExitIfOutOfMemory((void *)(active_kernel_properties_));
    }
    if (kernel_command_properties_ == nullptr) {
      kernel_command_properties_ = new std::map<uint64_t, ZeKernelCommandProperties>;
      UniMemory::ExitIfOutOfMemory((void *)(kernel_command_properties_));
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
      status = zeDriverGet(&num_drivers, drivers.data());
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
      for (auto driver : drivers) {

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

            uint32_t num_sub_devices = 0;
            status = zeDeviceGetSubDevices(device, &num_sub_devices, nullptr);
            PTI_ASSERT(status == ZE_RESULT_SUCCESS);

            desc.num_subdevices_ = num_sub_devices;

            desc.metric_group_ = nullptr;
            

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

  void DumpKernelProfiles(void) { // TODO
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
  }

 private: // Callbacks

  static void OnExitModuleCreate(ze_module_create_params_t* params, ze_result_t result, void* global_data, void** instance_user_data) { // TODO
    if (result == ZE_RESULT_SUCCESS) {
      ZeCollector* collector = reinterpret_cast<ZeCollector*>(global_data);
      ze_module_handle_t mod = **(params->pphModule);
      ze_device_handle_t device = *(params->phDevice);
      size_t binary_size;
      if (zeModuleGetNativeBinary(mod, &binary_size, nullptr) != ZE_RESULT_SUCCESS) {
        binary_size = (size_t)(-1);
      }

      ZeModule m;
      
      m.device_ = device;
      m.size_ = binary_size;
      m.aot_ = (*(params->pdesc))->format;
    
      modules_on_devices_mutex_.lock();
      modules_on_devices_.insert({mod, std::move(m)});
      modules_on_devices_mutex_.unlock();
    }
  }

  static void OnEnterModuleDestroy(ze_module_destroy_params_t* params, void* global_data, void** instance_user_data) { // TODO
    ZeCollector* collector = reinterpret_cast<ZeCollector*>(global_data);
    ze_module_handle_t mod = *(params->phModule);
    modules_on_devices_mutex_.lock();
    modules_on_devices_.erase(mod);
    modules_on_devices_mutex_.unlock();
  }

#if !defined(ZEX_STRUCTURE_KERNEL_REGISTER_FILE_SIZE_EXP)

#define ZEX_STRUCTURE_KERNEL_REGISTER_FILE_SIZE_EXP (ze_structure_type_t)0x00030012
typedef struct _zex_kernel_register_file_size_exp_t {
    ze_structure_type_t stype = ZEX_STRUCTURE_KERNEL_REGISTER_FILE_SIZE_EXP; ///< [in] type of this structure
    const void *pNext = nullptr;                                             ///< [in, out][optional] pointer to extension-specific structure
    uint32_t registerFileSize;                                               ///< [out] Register file size used in kernel
} zex_kernel_register_file_size_exp_t;

#endif /* !defined(ZEX_STRUCTURE_KERNEL_REGISTER_FILE_SIZE_EXP) */

  static void OnExitKernelCreate(ze_kernel_create_params_t *params, ze_result_t result, void* global_data, void** instance_user_data) { // TODO
    if (result == ZE_RESULT_SUCCESS) {
      ZeCollector* collector = reinterpret_cast<ZeCollector*>(global_data);
      ze_kernel_handle_t kernel = **(params->pphKernel);

      ze_module_handle_t mod = *(params->phModule);
      ze_device_handle_t device = nullptr;
      size_t module_binary_size = (size_t)(-1);
      bool aot = false;
      modules_on_devices_mutex_.lock_shared();
      auto mit = modules_on_devices_.find(mod);
      if (mit != modules_on_devices_.end()) {
        device = mit->second.device_; 
        module_binary_size = mit->second.size_;
        aot = mit->second.aot_;
      }
      modules_on_devices_mutex_.unlock_shared();

      int did = -1;
      if (device != nullptr) {
        devices_mutex_.lock_shared();
        auto dit = devices_->find(device);
        if (dit != devices_->end()) {
          did = dit->second.id_;
        } 
        devices_mutex_.unlock_shared();
      }
      kernel_command_properties_mutex_.lock();

      auto it = active_kernel_properties_->find(kernel);
      if (it != active_kernel_properties_->end()) {
        active_kernel_properties_->erase(it);
      }

      ZeKernelCommandProperties desc;

      desc.type_ = KERNEL_COMMAND_TYPE_COMPUTE;
      desc.aot_ = aot;

      ze_result_t status;

      desc.id_ = UniKernelId::GetKernelId();

      if ((*(params->pdesc) != nullptr) && ((*(params->pdesc))->pKernelName != nullptr)) {
        desc.name_ = std::string((*(params->pdesc))->pKernelName);
      }
      else {
        // try one more time
        size_t kname_size = 0;
        status = zeKernelGetName(kernel, &kname_size, nullptr);
        if ((status == ZE_RESULT_SUCCESS) && (kname_size > 0)) {
          char kname[kname_size];
          status = zeKernelGetName(kernel, &kname_size, kname);
          PTI_ASSERT(status == ZE_RESULT_SUCCESS);
          desc.name_ = std::string(kname);
        }
        else {
          desc.name_ = "UnknownKernel";
        }
      }

      desc.device_id_ = did;
      desc.device_ = device;

      ze_kernel_properties_t kprops{};

      zex_kernel_register_file_size_exp_t regsize{};
      kprops.pNext = (void *)&regsize;

      status = zeKernelGetProperties(kernel, &kprops);
      PTI_ASSERT(status == ZE_RESULT_SUCCESS);
      desc.simd_width_ = kprops.maxSubgroupSize;
      desc.nargs_ = kprops.numKernelArgs;
      desc.nsubgrps_ = kprops.maxNumSubgroups;
      desc.slmsize_ = kprops.localMemSize;
      desc.private_mem_size_ = kprops.privateMemSize;
      desc.spill_mem_size_ = kprops.spillMemSize;
      desc.regsize_ = regsize.registerFileSize;

      // for stall sampling
      uint64_t base_addr = 0;
      uint64_t binary_size = 0;
      if (collector->options_.stall_sampling && (zexKernelGetBaseAddress != nullptr) && (zexKernelGetBaseAddress(kernel, &base_addr) == ZE_RESULT_SUCCESS)) {
        base_addr &= 0xFFFFFFFF;
        binary_size = module_binary_size;	// store module binary size. only an upper bound is needed
      }

      desc.base_addr_ = base_addr;
      desc.size_ = binary_size;

      ZeKernelCommandProperties desc2 = desc;
      active_kernel_properties_->insert({kernel, std::move(desc)});
      kernel_command_properties_->insert({desc2.id_, std::move(desc2)});

      kernel_command_properties_mutex_.unlock();
    }
  }


  static void OnExitKernelDestroy(ze_kernel_destroy_params_t* params, ze_result_t result, void* global_data, void** instance_data) { // TODO
    if (result == ZE_RESULT_SUCCESS) {
      ZeCollector* collector = reinterpret_cast<ZeCollector*>(global_data);
      kernel_command_properties_mutex_.lock();
      active_kernel_properties_->erase(*(params->phKernel));
      kernel_command_properties_mutex_.unlock();
    }
  }

  #include <tracing.gen> // Auto-generated callbacks

 private: // Data
  zel_tracer_handle_t tracer_ = nullptr;
  CollectorOptions options_;
  std::string data_dir_name_;
};

#endif // PTI_TOOLS_UNITRACE_LEVEL_ZERO_COLLECTOR_H_
