//==============================================================
// Copyright (C) Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

#include <array>
#include <iostream>
#include <filesystem>
#include <csignal>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <dlfcn.h>
#include <stdlib.h>

#include "ze_metrics.h"
#include "utils.h"
#include "version.h"
#include "unitrace_commit_hash.h"

#define LIB_UNITRACE_TOOL_NAME	"libunitrace_tool.so"

static ZeMetricProfiler* metric_profiler = nullptr;

void Usage(char * progname) {
  std::cout <<
    "Usage: " << progname << " [options] <application> <args>" <<
    std::endl;
  std::cout <<
    "--metric-query [-q]            " <<
    "Query hardware metrics for each kernel instance" <<
    std::endl;
  std::cout <<
    "--metric-sampling [-k]         " <<
    "Sample hardware performance metrics for each kernel instance in time-based mode" <<
    std::endl;
  std::cout <<
    "--group [-g] <metric-group>    " <<
    "Hardware metric group (ComputeBasic by default)" <<
    std::endl;
  std::cout <<
    "--sampling-interval [-i] <interval> " <<
    "Hardware performance metric sampling interval in us (default is 50 us) in time-based mode" <<
    std::endl;
  std::cout <<
    "--device-list                  " <<
    "Print available devices" <<
    std::endl;
  std::cout <<
    "--metric-list                  " <<
    "Print available metric groups and metrics" <<
    std::endl;
  std::cout <<
    "--stall-sampling               " <<
    "Sample hardware execution unit stalls. Valid for Intel(R) Data Center GPU Max Series and later GPUs" <<
    std::endl;
  std::cout <<
    "--version                      " <<
    "Print version" <<
    std::endl;
}

void SetTracingEnvironment() {
  utils::SetEnv("ZE_ENABLE_TRACING_LAYER", "1");
}

void SetProfilingEnvironment() {
  utils::SetEnv("ZET_ENABLE_METRICS", "1");
}

void SetSysmanEnvironment() {
  utils::SetEnv("ZES_ENABLE_SYSMAN", "1");
}

int ParseArgs(int argc, char* argv[]) {
  bool show_metric_list = false;
  bool stall_sampling = false;
  bool metric_sampling = false;
  int app_index = 1;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--call-logging") == 0 || strcmp(argv[i], "-c") == 0) {
      utils::SetEnv("UNITRACE_CallLogging", "1");
      ++app_index;
    } else if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
      utils::SetEnv("UNITRACE_Verbose", "1");
      ++app_index;
    } else if (strcmp(argv[i], "--demangle") == 0) {
      utils::SetEnv("UNITRACE_Demangle", "1");
      ++app_index;
    } else if (strcmp(argv[i], "--output-dir-path") == 0) {
      ++i;
      utils::SetEnv("UNITRACE_TraceOutputDirPath", "1");
      utils::SetEnv("UNITRACE_TraceOutputDir", argv[i]);
      app_index += 2;
    } else if (strcmp(argv[i], "--metric-query") == 0 || strcmp(argv[i], "-q") == 0) {
      utils::SetEnv("UNITRACE_MetricQuery", "1");
      ++app_index;
    } else if (strcmp(argv[i], "--group") == 0 || strcmp(argv[i], "-g") == 0) {
      ++i;
      if (i >= argc) {
        std::cout << "[ERROR] Metric group is not specified" << std::endl;
        return -1;
      }
      utils::SetEnv("UNITRACE_MetricGroup", argv[i]);
      app_index += 2;
    } else if (strcmp(argv[i], "--stall-sampling") == 0) {
      stall_sampling = true;
      ++app_index;
    } else if (strcmp(argv[i], "--metric-sampling") == 0 || strcmp(argv[i], "-k") == 0) {
      utils::SetEnv("UNITRACE_KernelMetrics", "1");
      metric_sampling = true;
      ++app_index;
    } else if (strcmp(argv[i], "--sampling-interval") == 0 || strcmp(argv[i], "-i") == 0) {
      ++i;
      if (i >= argc) {
        std::cout << "[ERROR] Sampling interval is not specified" << std::endl;
        return -1;
      }
      utils::SetEnv("UNITRACE_SamplingInterval", argv[i]);
      app_index += 2;
    } else if (strcmp(argv[i], "--device-list") == 0) {
      SetSysmanEnvironment();	// enable ZES_ENABLE_SYSMAN
      PrintDeviceList();
      return 0;
    } else if (strcmp(argv[i], "--metric-list") == 0) {
      show_metric_list = true;
      ++app_index;
    } else if (strcmp(argv[i], "--version") == 0) {
      std::cout << UNITRACE_VERSION << " (" << COMMIT_HASH << ")" << std::endl;
      return 0;
    } else if (strcmp(argv[i], "--chrome-itt-logging") == 0 ) {
      utils::SetEnv("UNITRACE_ChromeIttLogging", "1");
      ++app_index;
    } else {
      break;
    }
  }

  if (stall_sampling) {
    if (metric_sampling && (utils::GetEnv("UNITRACE_MetricGroup") != "EuStallSampling")) {
      std::cerr << "[ERROR] Stall sampling cannot be enabled together with other metric group sampling" << std::endl;
      return 0;
    }
    if (utils::GetEnv("UNITRACE_MetricGroup").empty()) {
      utils::SetEnv("UNITRACE_MetricGroup", "EuStallSampling");
    }
    utils::SetEnv("UNITRACE_KernelMetrics", "1");
  }

  if (utils::GetEnv("UNITRACE_MetricQuery") == "1") {
    if (utils::GetEnv("UNITRACE_RawMetrics") == "1" || utils::GetEnv("UNITRACE_KernelMetrics") == "1") {
      std::cerr << "[ERROR] Hardware performance metric query mode cannot be used together with time-based mode" << std::endl;
      return 0;
    }
  }

  if ((utils::GetEnv("UNITRACE_MetricQuery") == "1") || (utils::GetEnv("UNITRACE_RawMetrics") == "1") || 
    (utils::GetEnv("UNITRACE_KernelMetrics") == "1")) {
    // kernel tracing must be on 
    if (utils::GetEnv("UNITRACE_DeviceTiming").empty() && utils::GetEnv("UNITRACE_ChromeKernelLogging").empty() && utils::GetEnv("UNITRACE_ChromeDeviceLogging").empty()) {
      utils::SetEnv("UNITRACE_DeviceTiming", "1");
    }

    // default metric group is "ComputeBasic"
    if (utils::GetEnv("UNITRACE_MetricGroup").empty()) {
      utils::SetEnv("UNITRACE_MetricGroup", "ComputeBasic");
    }

    // default sampling interval is 50 us
    // does not hurt to set UNITRACE_SamplingInterval in query mode
    if (utils::GetEnv("UNITRACE_SamplingInterval").empty()) {
      utils::SetEnv("UNITRACE_SamplingInterval", "50");
    }
  }

  if (!utils::GetEnv("UNITRACE_SamplingInterval").empty() || !utils::GetEnv("UNITRACE_MetricGroup").empty()) {
    if (utils::GetEnv("UNITRACE_DeviceTiming").empty() && utils::GetEnv("UNITRACE_ChromeKernelLogging").empty() && utils::GetEnv("UNITRACE_ChromeDeviceLogging").empty()) {
      std::cerr << "[ERROR] No time-based hardware performance metric sampling option (-k/--stall-sampling) specified" << std::endl;
    }
  }

  if (utils::GetEnv("UNITRACE_ChromeEventBufferSize").empty()) {
    utils::SetEnv("UNITRACE_ChromeEventBufferSize", "-1");	// does not hurt to set to default even if chrome logging is not enabled
  }

  if (show_metric_list) {
    SetProfilingEnvironment();	// enable ZET_ENABLE_METRICS
    std::string value = utils::GetEnv("UNITRACE_DeviceId");
    uint32_t device_id = value.empty() ? 0 : std::stoul(value);
    PrintMetricList(device_id);
    return 0;
  }

  // __itt_pause()/__itt_resume() support always enabled
  utils::SetEnv("INTEL_LIBITTNOTIFY64", "libunitrace_tool.so");

  return app_index;
}

void EnableProfiling(char *dir, std::string& logfile) {
  if (zeInit(ZE_INIT_FLAG_GPU_ONLY) != ZE_RESULT_SUCCESS) {
    std::cerr << "[ERROR] Failed to initialize Level Zero runtime" << std::endl;
    std::cerr << "Please make sure /proc/sys/dev/i915/perf_stream_paranoid is set to 0." << std::endl;
    exit(-1);
  }
  metric_profiler = ZeMetricProfiler::Create(dir, logfile);
}

void DisableProfiling() {
  if (metric_profiler != nullptr) {
    delete metric_profiler;
  }
}

static char pattern[] = "/tmp/tmpdir.XXXXXX";
static char *data_dir = nullptr;

void CleanUp(int sig) {
  if (data_dir == nullptr) {
    return;
  }
  for (const auto& e: std::filesystem::directory_iterator(std::filesystem::path(data_dir))) {
    std::filesystem::remove_all(e.path());
  }
  if (remove(data_dir)) {
    std::cerr << "[WARNING] " << data_dir << " is not removed. Please manually remove it." << std::endl;
  }
  _Exit(-1);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    Usage(argv[0]);
    return 0;
  }

  struct rlimit	rlim;
  rlim.rlim_cur = RLIM_INFINITY;
  rlim.rlim_max = RLIM_INFINITY;
  if (setrlimit(RLIMIT_STACK, &rlim)) {
    // cannot set stack size to unlimited
    // set soft limit to the same as hard limit
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_STACK, &rlim);
  }

  std::string executable_path = utils::GetExecutablePath();

  bool use_ld_lib_path = false;
  std::string lib_path = executable_path + LIB_UNITRACE_TOOL_NAME;
  FILE *fp = fopen(lib_path.c_str(), "rb");
  if (fp == nullptr) {
    use_ld_lib_path = true;
    lib_path = LIB_UNITRACE_TOOL_NAME;
  }
  else {
    fclose(fp);
  }

  // Set unitrace version
  auto unitrace_version =  std::string(UNITRACE_VERSION) + " (" +  std::string(COMMIT_HASH) + ")";
  utils::SetEnv("UNITRACE_VERSION", unitrace_version.c_str());

  int app_index = ParseArgs(argc, argv);
  if (app_index <= 0 || app_index >= argc) {
    if (app_index >= argc) {
      std::cerr << "[ERROR] Application is missing" << std::endl;
      Usage(argv[0]);
    } else if (app_index < 0) {
      std::cerr << "[ERROR] Invalid command line" << std::endl;
      Usage(argv[0]);
    }
    return 0;
  }
  std::vector<char*> app_args;
  
  for (int i = app_index; i < argc; ++i) {
    app_args.push_back(argv[i]);
  }
  app_args.push_back(nullptr);

  std::string preload = utils::GetEnv("LD_PRELOAD");
  if (preload.empty()) {
    preload = std::move(lib_path);
  }
  else {
    preload = preload + ":" + lib_path;
  }

  SetTracingEnvironment();
  if (utils::GetEnv("UNITRACE_MetricQuery") == "1") {
    // UNITRACE_RawMetrics or UNITRACE_KernelMetrics is not set
    SetProfilingEnvironment();
  }

  utils::SetEnv("LD_PRELOAD", preload.c_str());
  utils::SetEnv("PTI_ENABLE", "1");

  if ((utils::GetEnv("UNITRACE_RawMetrics") == "1") || (utils::GetEnv("UNITRACE_KernelMetrics") == "1")) {

    // UNITRACE_MetricQuery is not set
    SetProfilingEnvironment();

    data_dir = mkdtemp(pattern);
    if (data_dir == nullptr) {
      std::cerr << "[ERROR] Failed to create data folder" << std::endl;
      exit(-1);
    }

    std::string logfile;
    if (utils::GetEnv("UNITRACE_LogToFile") == "1") {
      logfile = utils::GetEnv("UNITRACE_LogFilename");
    }
    
    std::signal(SIGABRT, CleanUp);
    std::signal(SIGFPE, CleanUp);
    std::signal(SIGILL, CleanUp);
    std::signal(SIGINT, CleanUp);
    std::signal(SIGSEGV, CleanUp);
    std::signal(SIGTERM, CleanUp);

    EnableProfiling(data_dir, logfile);

    int child;

    child = fork();
    if (child == 0) {
      // child process
      utils::SetEnv("UNITRACE_DataDir", data_dir);
      if (execvp(app_args[0], app_args.data())) {
        std::cerr << "[ERROR] Failed to launch target application: " << app_args[0] << std::endl;
        Usage(argv[0]);
       
        std::_Exit(-1);
      }
    } else if (child > 0) {
      // parent process

      // wait for child process to complete
      while (wait(nullptr) > 0);

      DisableProfiling();
      for (const auto& e: std::filesystem::directory_iterator(std::filesystem::path(data_dir))) {
        std::filesystem::remove_all(e.path());
      }
      if (remove(data_dir)) {
        std::cerr << "[WARNING] " << data_dir << " is not removed. Please manually remove it." << std::endl;
      }
    } else {
      std::cerr << "[ERROR] Failed to create child process" << std::endl;
      DisableProfiling();
      for (const auto& e: std::filesystem::directory_iterator(std::filesystem::path(data_dir))) {
        std::filesystem::remove_all(e.path());
      }
      remove(data_dir);
    }
  }
  else {
    if (execvp(app_args[0], app_args.data())) {
      std::cerr << "[ERROR] Failed to launch target application: " << app_args[0] << std::endl;
      Usage(argv[0]);
    }
  }

  return 0;
}
