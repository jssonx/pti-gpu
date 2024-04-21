//==============================================================
// Copyright (C) Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

#ifndef PTI_TOOLS_UNITRACE_UNIFIED_TRACER_H_
#define PTI_TOOLS_UNITRACE_UNIFIED_TRACER_H_

#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "trace_options.h"
#include "utils.h"
#include "ze_collector.h"
#include "unimemory.h"

static std::string GetChromeTraceFileName(void) {
  std::ifstream comm("/proc/self/comm");
  if (comm) {
    std::string name;
    std::getline(comm, name);
    comm.close();
    if (!name.empty()) {
      return std::move(name);
    }
  }

  // should never get here
  return "unitrace";
}

class UniTracer {
 public:
  static UniTracer* Create(const TraceOptions& options) {
    ze_result_t status = ZE_RESULT_SUCCESS;
    status = zeInit(ZE_INIT_FLAG_GPU_ONLY);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);

    UniTracer* tracer = new UniTracer(options);
    UniMemory::ExitIfOutOfMemory((void *)tracer);

    //TODO: cleanup option setting
    CollectorOptions collector_options;
    collector_options.device_timing = false;
    collector_options.kernel_submission = false;
    collector_options.host_timing = false;
    collector_options.kernel_tracing = false;
    collector_options.api_tracing = false;
    collector_options.metric_query = false;
    collector_options.metric_stream = false;
    collector_options.stall_sampling = false;
    OnZeKernelFinishCallback ze_kcallback = nullptr;
    OnZeFunctionFinishCallback ze_fcallback = nullptr;
    ZeCollector* ze_collector = nullptr;

        
    if (tracer->CheckOption(TRACE_DEVICE_TIMING) ||
        tracer->CheckOption(TRACE_DEVICE_TIMELINE) ||
        tracer->CheckOption(TRACE_KERNEL_SUBMITTING) ||
        tracer->CheckOption(TRACE_CHROME_DEVICE_LOGGING) ||
        tracer->CheckOption(TRACE_CHROME_KERNEL_LOGGING)) {

      collector_options.kernel_tracing = true;
      collector_options.device_timing = tracer->CheckOption(TRACE_DEVICE_TIMING);
      collector_options.device_timeline = tracer->CheckOption(TRACE_DEVICE_TIMELINE);
      collector_options.kernel_submission = tracer->CheckOption(TRACE_KERNEL_SUBMITTING);
      collector_options.verbose = tracer->CheckOption(TRACE_VERBOSE);
      collector_options.demangle = tracer->CheckOption(TRACE_DEMANGLE);
      collector_options.kernels_per_tile = tracer->CheckOption(TRACE_KERNELS_PER_TILE);
    }


    if (tracer->CheckOption(TRACE_CALL_LOGGING) ||
        tracer->CheckOption(TRACE_CHROME_CALL_LOGGING) ||
        tracer->CheckOption(TRACE_HOST_TIMING)) {

      collector_options.api_tracing = true;
      collector_options.host_timing = tracer->CheckOption(TRACE_HOST_TIMING);
      collector_options.call_logging = tracer->CheckOption(TRACE_CALL_LOGGING);
      collector_options.need_tid = tracer->CheckOption(TRACE_TID);
      collector_options.need_pid = tracer->CheckOption(TRACE_PID);
      collector_options.demangle = tracer->CheckOption(TRACE_DEMANGLE);
    }

    if (tracer->CheckOption(TRACE_METRIC_QUERY)) {
      collector_options.metric_query = true;
    }

    if (tracer->CheckOption(TRACE_METRIC_STREAM)) {
      collector_options.metric_stream = true;
      if (utils::GetEnv("UNITRACE_MetricGroup") == "EuStallSampling") {
        collector_options.stall_sampling = true;
      }
    }

    if (collector_options.kernel_tracing || collector_options.api_tracing) {

      ze_collector = ZeCollector::Create(&tracer->correlator_, collector_options, ze_kcallback, ze_fcallback, tracer);
      if (ze_collector == nullptr) {
        std::cerr <<
          "[WARNING] Unable to create kernel collector for L0 backend" <<
          std::endl;
      }
      tracer->ze_collector_ = ze_collector;
    }

    return tracer;
  }

  ~UniTracer() {
    total_execution_time_ = correlator_.GetTimestamp();

    if (ze_collector_ != nullptr) {
      ze_collector_->DisableTracing();
      delete ze_collector_;
    }

    // report after ze_collector_ is destructed
    // local stats are sweeped in deconstructor
    Report();

    if (CheckOption(TRACE_LOG_TO_FILE)) {
      std::cerr << "[INFO] Log is stored in " <<
        options_.GetLogFileName() << std::endl;
    }
  }

  bool CheckOption(uint32_t option) {
    return options_.CheckFlag(option);
  }

  UniTracer(const UniTracer& that) = delete;
  UniTracer& operator=(const UniTracer& that) = delete;

 private:
  UniTracer(const TraceOptions& options)
      : options_(options),
        correlator_(options.GetLogFileName(),
          CheckOption(TRACE_CONDITIONAL_COLLECTION)) {
  }

  static uint64_t CalculateTotalFunctionTime(const ZeCollector* collector) {
    return collector->CalculateTotalFunctionTime();
  }

  static uint64_t CalculateTotalKernelTime(const ZeCollector* collector) {
    return collector->CalculateTotalKernelTime();
  }

  void PrintFunctionTable(
      const ZeCollector* collector, const char* device_type) {
    PTI_ASSERT(collector != nullptr);
    PTI_ASSERT(device_type != nullptr);

    uint64_t total_duration = CalculateTotalFunctionTime(collector);
    if (total_duration > 0) {
      std::string str("\n== ");
      str += std::string(device_type) + " Backend ==\n\n";
      correlator_.Log(str);
      collector->PrintFunctionsTable();
    }
  }

  void PrintKernelTable(
      const ZeCollector* collector, const char* device_type) {
    PTI_ASSERT(collector != nullptr);
    PTI_ASSERT(device_type != nullptr);

    uint64_t total_duration = CalculateTotalKernelTime(collector);
    if (total_duration > 0) {
      std::string str("\n== ");
      str += std::string(device_type) + " Backend ==\n\n";
      correlator_.Log(str);
      collector->PrintKernelsTable();
    }
  }

  void PrintSubmissionTable(
      const ZeCollector* collector, const char* device_type) {
    PTI_ASSERT(collector != nullptr);
    PTI_ASSERT(device_type != nullptr);

    uint64_t total_duration = CalculateTotalKernelTime(collector);
    if (total_duration > 0) {
      std::string str("\n== ");
      str += std::string(device_type) + " Backend ==\n\n";
      correlator_.Log(str);
      collector->PrintSubmissionTable();
    }
  }


  template <class L0Collector>
  void ReportTiming(
      const L0Collector* ze_collector,
      const char* type) {
    PTI_ASSERT(ze_collector != nullptr);

    std::string stype = std::string(type);

    std::string ze_title =
      std::string("Total ") + stype +
      " Time for L0 backend (ns): ";
    size_t title_width = ze_title.size();
    const size_t time_width = 20;

    std::string str("\n=== ");
    str += stype + " Timing Summary ===\n\n" + 
           std::string(std::max(int(title_width - sizeof("Total Execution Time (ns): ") + 1), 0), ' ') +
           "Total Execution Time (ns): " +
           std::string(std::max(int(time_width - std::to_string(total_execution_time_).length()), 0), ' ') +
           std::to_string(total_execution_time_) + 
           "\n";

    if (ze_collector != nullptr) {
      uint64_t total_time = 0;
      if (stype == "API") {
        total_time = CalculateTotalFunctionTime(ze_collector);
      }
      if (stype == "Device") {
        total_time = CalculateTotalKernelTime(ze_collector);
      }
      if (total_time > 0) {
        str += std::string(std::max(int(title_width - ze_title.length()), 0), ' ') + ze_title +
               std::string(std::max(int(time_width - std::to_string(total_time).length()), 0), ' ') + std::to_string(total_time) +
               "\n";
      }
    }

    correlator_.Log(str);

    if (ze_collector != nullptr) {
      if (stype == "API") {
        PrintFunctionTable(ze_collector, "L0");
      }
      if (stype == "Device") {
        PrintKernelTable(ze_collector, "L0");
      }
    }

    correlator_.Log("\n");
  }

  void ReportKernelSubmission(
      const ZeCollector* ze_collector,
      const char* type) {
    PTI_ASSERT(ze_collector != nullptr);

    std::string ze_title =
      std::string("Total ") + std::string(type) +
      " Time for L0 backend (ns): ";
    size_t title_width = ze_title.size();
    const size_t time_width = 20;

    std::string str("\n=== Kernel Submission Summary ===\n\n");
    str += std::string(std::max(int(title_width - sizeof("Total Execution Time (ns): ") + 1), 0), ' ') + "Total Execution Time (ns): " +
           std::string(std::max(int(time_width - std::to_string(total_execution_time_).length()), 0), ' ') + std::to_string(total_execution_time_)           + "\n";

    if (ze_collector != nullptr) {
      uint64_t total_time = CalculateTotalKernelTime(ze_collector);
      if (total_time > 0) {
        str += std::string(std::max(int(title_width - ze_title.length()), 0), ' ') + ze_title +
               std::string(std::max(int(time_width - std::to_string(total_time).length()), 0), ' ') + std::to_string(total_time) +
               "\n";
      }
    }

    correlator_.Log(str);

    if (ze_collector != nullptr) {
      PrintSubmissionTable(ze_collector, "L0");
    }

    correlator_.Log("\n");
  }

  void Report() {
    if (CheckOption(TRACE_HOST_TIMING)) {
      ReportTiming(
          ze_collector_,
          "API");
    }
    if (CheckOption(TRACE_DEVICE_TIMING)) {
      ReportTiming(
          ze_collector_,
          "Device");
    }
    if (CheckOption(TRACE_KERNEL_SUBMITTING)) {
      ReportKernelSubmission(
          ze_collector_,
          "Device");
    }
    correlator_.Log("\n");
  }

 private:
  TraceOptions options_;

  Correlator correlator_;
  uint64_t total_execution_time_ = 0;

  ZeCollector* ze_collector_ = nullptr;
};

#endif // PTI_TOOLS_UNITRACE_UNIFIED_TRACER_H_

