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

#include "ze_metrics.h"
#include "utils.h"

#define LIB_UNITRACE_TOOL_NAME	"libunitrace_tool.so"

static ZeMetricProfiler* metric_profiler = nullptr;

void Usage(char * progname) {
  std::cout <<
    "--sampling-interval [-i] <interval> " <<
    "Hardware performance metric sampling interval in us (default is 50 us) in time-based mode" <<
    std::endl;
  std::cout <<
    "--stall-sampling               " <<
    "Sample hardware execution unit stalls. Valid for Intel(R) Data Center GPU Max Series and later GPUs" <<
    std::endl;
}

void SetTracingEnvironment() {
  utils::SetEnv("ZE_ENABLE_TRACING_LAYER", "1");
}

void SetProfilingEnvironment() {
  utils::SetEnv("ZET_ENABLE_METRICS", "1");
}

int ParseArgs(int argc, char* argv[]) {
  bool stall_sampling = false;
  int app_index = 1;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--stall-sampling") == 0) {
      stall_sampling = true;
      ++app_index;
    } else if (strcmp(argv[i], "--sampling-interval") == 0 || strcmp(argv[i], "-i") == 0) {
      ++i;
      if (i >= argc) {
        std::cout << "[ERROR] Sampling interval is not specified" << std::endl;
        return -1;
      }
      utils::SetEnv("UNITRACE_SamplingInterval", argv[i]);
      app_index += 2;
    } else if (strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0) {
      utils::SetEnv("UNITRACE_LogToFile", "1");
      ++i;
      if (i >= argc) {
        std::cerr << "[ERROR] Log file name is not specified" << std::endl;
        return -1;
      }
      utils::SetEnv("UNITRACE_LogFilename", argv[i]);
      app_index += 2;
    } else {
      break;
    }
  }

  if (stall_sampling) {
    if (utils::GetEnv("UNITRACE_MetricGroup").empty()) {
      utils::SetEnv("UNITRACE_MetricGroup", "EuStallSampling");
    }
    utils::SetEnv("UNITRACE_KernelMetrics", "1");
  }

  if (utils::GetEnv("UNITRACE_KernelMetrics") == "1") {
    // kernel tracing must be on 
    if (utils::GetEnv("UNITRACE_DeviceTiming").empty()) {
      utils::SetEnv("UNITRACE_DeviceTiming", "1");
    }

    // default sampling interval is 50 us
    // does not hurt to set UNITRACE_SamplingInterval in query mode
    if (utils::GetEnv("UNITRACE_SamplingInterval").empty()) {
      utils::SetEnv("UNITRACE_SamplingInterval", "50");
    }
  }

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

  utils::SetEnv("LD_PRELOAD", preload.c_str());
  utils::SetEnv("PTI_ENABLE", "1");

  if (utils::GetEnv("UNITRACE_KernelMetrics") == "1") {

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
