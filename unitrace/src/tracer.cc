//==============================================================
// Copyright (C) Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

#include <iostream>

#include "tracer.h"

static UniTracer* tracer = nullptr;

static TraceOptions ReadArgs() {
  std::string value;
  uint32_t flags = 0;
  std::string log_file;

  value = utils::GetEnv("UNITRACE_DeviceTiming");
  if (!value.empty() && value == "1") {
    flags |= (1 << TRACE_DEVICE_TIMING);
  }

  value = utils::GetEnv("UNITRACE_KernelMetrics");
  if (!value.empty()) {
    flags |= (1 << TRACE_METRIC_STREAM);
  }

  return TraceOptions(flags, log_file);
}

void __attribute__((constructor)) Init(void) {
  std::string value = utils::GetEnv("PTI_ENABLE");
  if (value != "1") {
    return;
  }

  if (!tracer) {
    tracer = UniTracer::Create(ReadArgs());
  }
}

void __attribute__((destructor)) Fini(void) {
  std::string value = utils::GetEnv("PTI_ENABLE");
  if (value != "1") {
    return;
  }

  if (tracer != nullptr) {
    delete tracer;
  }
}
