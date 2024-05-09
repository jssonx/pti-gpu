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

#include "ze_collector.h"
#include "unimemory.h"
#include "ze_debug_info_collector.h"


class UniTracer {
 public:
  static UniTracer* Create() {
    ze_result_t status = ZE_RESULT_SUCCESS;
    status = zeInit(ZE_INIT_FLAG_GPU_ONLY);
    PTI_ASSERT(status == ZE_RESULT_SUCCESS);

    UniTracer* tracer = new UniTracer();
    UniMemory::ExitIfOutOfMemory((void *)tracer);

    ZeCollector* ze_collector = nullptr;
    ze_collector = ZeCollector::Create();
    if (ze_collector == nullptr) {
      std::cerr <<
        "[WARNING] Unable to create kernel collector for L0 backend" <<
        std::endl;
    }
    tracer->ze_collector_ = ze_collector;
    
    return tracer;
  }

  ~UniTracer() {
    if (za_debug_collector != nullptr) {
      za_debug_collector->DisableTracing();
      PrintResults();
      delete za_debug_collector;
    }

    if (ze_collector_ != nullptr) {
      ze_collector_->DisableTracing();
      delete ze_collector_;
    }
  }

  UniTracer(const UniTracer& that) = delete;
  UniTracer& operator=(const UniTracer& that) = delete;

 private:
  UniTracer(){
    utils::SetEnv("PTI_ENABLE", "1");
    za_debug_collector = ZeDebugInfoCollector::Create();
  }

  void PrintResults() {
    PTI_ASSERT(za_debug_collector != nullptr);

    const KernelDebugInfoMap& debug_info_map =
      za_debug_collector->GetKernelDebugInfoMap();
    if (debug_info_map.size() == 0) {
      return;
    }

    std::cerr << std::endl;
    for (auto pair : debug_info_map) {
      ZeDebugInfoCollector::PrintKernelDebugInfo(pair.first, pair.second);
    }
  }

 private:
  ZeCollector* ze_collector_ = nullptr;
  ZeDebugInfoCollector* za_debug_collector = nullptr;
};


#endif // PTI_TOOLS_UNITRACE_UNIFIED_TRACER_H_
