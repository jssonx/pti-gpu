static const char* GetResultString(unsigned result) {
  switch (result) {
    case ZE_RESULT_SUCCESS:
      return "ZE_RESULT_SUCCESS";
    case ZE_RESULT_NOT_READY:
      return "ZE_RESULT_NOT_READY";
    case ZE_RESULT_ERROR_DEVICE_LOST:
      return "ZE_RESULT_ERROR_DEVICE_LOST";
    case ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY:
      return "ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY";
    case ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY:
      return "ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY";
    case ZE_RESULT_ERROR_MODULE_BUILD_FAILURE:
      return "ZE_RESULT_ERROR_MODULE_BUILD_FAILURE";
    case ZE_RESULT_ERROR_MODULE_LINK_FAILURE:
      return "ZE_RESULT_ERROR_MODULE_LINK_FAILURE";
    case ZE_RESULT_ERROR_DEVICE_REQUIRES_RESET:
      return "ZE_RESULT_ERROR_DEVICE_REQUIRES_RESET";
    case ZE_RESULT_ERROR_DEVICE_IN_LOW_POWER_STATE:
      return "ZE_RESULT_ERROR_DEVICE_IN_LOW_POWER_STATE";
    case ZE_RESULT_ERROR_INSUFFICIENT_PERMISSIONS:
      return "ZE_RESULT_ERROR_INSUFFICIENT_PERMISSIONS";
    case ZE_RESULT_ERROR_NOT_AVAILABLE:
      return "ZE_RESULT_ERROR_NOT_AVAILABLE";
    case ZE_RESULT_ERROR_DEPENDENCY_UNAVAILABLE:
      return "ZE_RESULT_ERROR_DEPENDENCY_UNAVAILABLE";
    case ZE_RESULT_WARNING_DROPPED_DATA:
      return "ZE_RESULT_WARNING_DROPPED_DATA";
    case ZE_RESULT_ERROR_UNINITIALIZED:
      return "ZE_RESULT_ERROR_UNINITIALIZED";
    case ZE_RESULT_ERROR_UNSUPPORTED_VERSION:
      return "ZE_RESULT_ERROR_UNSUPPORTED_VERSION";
    case ZE_RESULT_ERROR_UNSUPPORTED_FEATURE:
      return "ZE_RESULT_ERROR_UNSUPPORTED_FEATURE";
    case ZE_RESULT_ERROR_INVALID_ARGUMENT:
      return "ZE_RESULT_ERROR_INVALID_ARGUMENT";
    case ZE_RESULT_ERROR_INVALID_NULL_HANDLE:
      return "ZE_RESULT_ERROR_INVALID_NULL_HANDLE";
    case ZE_RESULT_ERROR_HANDLE_OBJECT_IN_USE:
      return "ZE_RESULT_ERROR_HANDLE_OBJECT_IN_USE";
    case ZE_RESULT_ERROR_INVALID_NULL_POINTER:
      return "ZE_RESULT_ERROR_INVALID_NULL_POINTER";
    case ZE_RESULT_ERROR_INVALID_SIZE:
      return "ZE_RESULT_ERROR_INVALID_SIZE";
    case ZE_RESULT_ERROR_UNSUPPORTED_SIZE:
      return "ZE_RESULT_ERROR_UNSUPPORTED_SIZE";
    case ZE_RESULT_ERROR_UNSUPPORTED_ALIGNMENT:
      return "ZE_RESULT_ERROR_UNSUPPORTED_ALIGNMENT";
    case ZE_RESULT_ERROR_INVALID_SYNCHRONIZATION_OBJECT:
      return "ZE_RESULT_ERROR_INVALID_SYNCHRONIZATION_OBJECT";
    case ZE_RESULT_ERROR_INVALID_ENUMERATION:
      return "ZE_RESULT_ERROR_INVALID_ENUMERATION";
    case ZE_RESULT_ERROR_UNSUPPORTED_ENUMERATION:
      return "ZE_RESULT_ERROR_UNSUPPORTED_ENUMERATION";
    case ZE_RESULT_ERROR_UNSUPPORTED_IMAGE_FORMAT:
      return "ZE_RESULT_ERROR_UNSUPPORTED_IMAGE_FORMAT";
    case ZE_RESULT_ERROR_INVALID_NATIVE_BINARY:
      return "ZE_RESULT_ERROR_INVALID_NATIVE_BINARY";
    case ZE_RESULT_ERROR_INVALID_GLOBAL_NAME:
      return "ZE_RESULT_ERROR_INVALID_GLOBAL_NAME";
    case ZE_RESULT_ERROR_INVALID_KERNEL_NAME:
      return "ZE_RESULT_ERROR_INVALID_KERNEL_NAME";
    case ZE_RESULT_ERROR_INVALID_FUNCTION_NAME:
      return "ZE_RESULT_ERROR_INVALID_FUNCTION_NAME";
    case ZE_RESULT_ERROR_INVALID_GROUP_SIZE_DIMENSION:
      return "ZE_RESULT_ERROR_INVALID_GROUP_SIZE_DIMENSION";
    case ZE_RESULT_ERROR_INVALID_GLOBAL_WIDTH_DIMENSION:
      return "ZE_RESULT_ERROR_INVALID_GLOBAL_WIDTH_DIMENSION";
    case ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX:
      return "ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX";
    case ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE:
      return "ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE";
    case ZE_RESULT_ERROR_INVALID_KERNEL_ATTRIBUTE_VALUE:
      return "ZE_RESULT_ERROR_INVALID_KERNEL_ATTRIBUTE_VALUE";
    case ZE_RESULT_ERROR_INVALID_MODULE_UNLINKED:
      return "ZE_RESULT_ERROR_INVALID_MODULE_UNLINKED";
    case ZE_RESULT_ERROR_INVALID_COMMAND_LIST_TYPE:
      return "ZE_RESULT_ERROR_INVALID_COMMAND_LIST_TYPE";
    case ZE_RESULT_ERROR_OVERLAPPING_REGIONS:
      return "ZE_RESULT_ERROR_OVERLAPPING_REGIONS";
    case ZE_RESULT_WARNING_ACTION_REQUIRED:
      return "ZE_RESULT_WARNING_ACTION_REQUIRED";
    case ZE_RESULT_EXP_ERROR_DEVICE_IS_NOT_VERTEX:
      return "ZE_RESULT_EXP_ERROR_DEVICE_IS_NOT_VERTEX";
    case ZE_RESULT_EXP_ERROR_VERTEX_IS_NOT_DEVICE:
      return "ZE_RESULT_EXP_ERROR_VERTEX_IS_NOT_DEVICE";
    case ZE_RESULT_EXP_ERROR_REMOTE_DEVICE:
      return "ZE_RESULT_EXP_ERROR_REMOTE_DEVICE";
    case ZE_RESULT_ERROR_UNKNOWN:
      return "ZE_RESULT_ERROR_UNKNOWN";
    case ZE_RESULT_FORCE_UINT32:
      return "ZE_RESULT_FORCE_UINT32";
    default:
      break;
  }
  return "UNKNOWN";
}

static const char* GetStructureTypeString(unsigned structure_type) {
  switch (structure_type) {
    case ZE_STRUCTURE_TYPE_DRIVER_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DRIVER_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DRIVER_IPC_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DRIVER_IPC_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_COMPUTE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_COMPUTE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_MODULE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_MODULE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_COMMAND_QUEUE_GROUP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_COMMAND_QUEUE_GROUP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_MEMORY_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_MEMORY_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_MEMORY_ACCESS_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_MEMORY_ACCESS_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_CACHE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_CACHE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_IMAGE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_IMAGE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_P2P_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_P2P_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_EXTERNAL_MEMORY_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_EXTERNAL_MEMORY_PROPERTIES";
    case ZE_STRUCTURE_TYPE_CONTEXT_DESC:
      return "ZE_STRUCTURE_TYPE_CONTEXT_DESC";
    case ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC:
      return "ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC";
    case ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC:
      return "ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC";
    case ZE_STRUCTURE_TYPE_EVENT_POOL_DESC:
      return "ZE_STRUCTURE_TYPE_EVENT_POOL_DESC";
    case ZE_STRUCTURE_TYPE_EVENT_DESC:
      return "ZE_STRUCTURE_TYPE_EVENT_DESC";
    case ZE_STRUCTURE_TYPE_FENCE_DESC:
      return "ZE_STRUCTURE_TYPE_FENCE_DESC";
    case ZE_STRUCTURE_TYPE_IMAGE_DESC:
      return "ZE_STRUCTURE_TYPE_IMAGE_DESC";
    case ZE_STRUCTURE_TYPE_IMAGE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_IMAGE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC:
      return "ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC";
    case ZE_STRUCTURE_TYPE_HOST_MEM_ALLOC_DESC:
      return "ZE_STRUCTURE_TYPE_HOST_MEM_ALLOC_DESC";
    case ZE_STRUCTURE_TYPE_MEMORY_ALLOCATION_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_MEMORY_ALLOCATION_PROPERTIES";
    case ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_DESC:
      return "ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_DESC";
    case ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_FD:
      return "ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_FD";
    case ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_FD:
      return "ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_FD";
    case ZE_STRUCTURE_TYPE_MODULE_DESC:
      return "ZE_STRUCTURE_TYPE_MODULE_DESC";
    case ZE_STRUCTURE_TYPE_MODULE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_MODULE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_KERNEL_DESC:
      return "ZE_STRUCTURE_TYPE_KERNEL_DESC";
    case ZE_STRUCTURE_TYPE_KERNEL_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_KERNEL_PROPERTIES";
    case ZE_STRUCTURE_TYPE_SAMPLER_DESC:
      return "ZE_STRUCTURE_TYPE_SAMPLER_DESC";
    case ZE_STRUCTURE_TYPE_PHYSICAL_MEM_DESC:
      return "ZE_STRUCTURE_TYPE_PHYSICAL_MEM_DESC";
    case ZE_STRUCTURE_TYPE_KERNEL_PREFERRED_GROUP_SIZE_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_KERNEL_PREFERRED_GROUP_SIZE_PROPERTIES";
    case ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_WIN32:
      return "ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_WIN32";
    case ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_WIN32:
      return "ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_WIN32";
    case ZE_STRUCTURE_TYPE_DEVICE_RAYTRACING_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_RAYTRACING_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_RAYTRACING_MEM_ALLOC_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_RAYTRACING_MEM_ALLOC_EXT_DESC";
    case ZE_STRUCTURE_TYPE_FLOAT_ATOMIC_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_FLOAT_ATOMIC_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_CACHE_RESERVATION_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_CACHE_RESERVATION_EXT_DESC";
    case ZE_STRUCTURE_TYPE_EU_COUNT_EXT:
      return "ZE_STRUCTURE_TYPE_EU_COUNT_EXT";
    case ZE_STRUCTURE_TYPE_SRGB_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_SRGB_EXT_DESC";
    case ZE_STRUCTURE_TYPE_LINKAGE_INSPECTION_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_LINKAGE_INSPECTION_EXT_DESC";
    case ZE_STRUCTURE_TYPE_PCI_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_PCI_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DRIVER_MEMORY_FREE_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DRIVER_MEMORY_FREE_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_MEMORY_FREE_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_MEMORY_FREE_EXT_DESC";
    case ZE_STRUCTURE_TYPE_MEMORY_COMPRESSION_HINTS_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_MEMORY_COMPRESSION_HINTS_EXT_DESC";
    case ZE_STRUCTURE_TYPE_IMAGE_ALLOCATION_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_IMAGE_ALLOCATION_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_LUID_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_LUID_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_MEMORY_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_MEMORY_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_IP_VERSION_EXT:
      return "ZE_STRUCTURE_TYPE_DEVICE_IP_VERSION_EXT";
    case ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXT_DESC:
      return "ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXT_DESC";
    case ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_RESULTS_EXT_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_RESULTS_EXT_PROPERTIES";
    case ZE_STRUCTURE_TYPE_RELAXED_ALLOCATION_LIMITS_EXP_DESC:
      return "ZE_STRUCTURE_TYPE_RELAXED_ALLOCATION_LIMITS_EXP_DESC";
    case ZE_STRUCTURE_TYPE_MODULE_PROGRAM_EXP_DESC:
      return "ZE_STRUCTURE_TYPE_MODULE_PROGRAM_EXP_DESC";
    case ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_DESC:
      return "ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_DESC";
    case ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXP_DESC:
      return "ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXP_DESC";
    case ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES_1_2:
      return "ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES_1_2";
    case ZE_STRUCTURE_TYPE_IMAGE_MEMORY_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_IMAGE_MEMORY_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_POWER_SAVING_HINT_EXP_DESC:
      return "ZE_STRUCTURE_TYPE_POWER_SAVING_HINT_EXP_DESC";
    case ZE_STRUCTURE_TYPE_COPY_BANDWIDTH_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_COPY_BANDWIDTH_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_DEVICE_P2P_BANDWIDTH_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_DEVICE_P2P_BANDWIDTH_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_FABRIC_VERTEX_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_FABRIC_VERTEX_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_FABRIC_EDGE_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_FABRIC_EDGE_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_MEMORY_SUB_ALLOCATIONS_EXP_PROPERTIES:
      return "ZE_STRUCTURE_TYPE_MEMORY_SUB_ALLOCATIONS_EXP_PROPERTIES";
    case ZE_STRUCTURE_TYPE_FORCE_UINT32:
      return "ZE_STRUCTURE_TYPE_FORCE_UINT32";
    default:
      break;
  }
  return "UNKNOWN";
}

static void zeInitOnEnter(
    ze_init_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeInit:";
    str += " flags = " + std::to_string((long long unsigned int)*(params->pflags));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeInitOnExit(
    ze_init_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeInit";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDriverGetOnEnter(
    ze_driver_get_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDriverGet:";
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " phDrivers = " + std::to_string((long long unsigned int)*(params->pphDrivers));
    if (*(params->pphDrivers) != nullptr) {
      str += " (hDrivers = " + std::to_string((long long unsigned int)**(params->pphDrivers)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDriverGetOnExit(
    ze_driver_get_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDriverGet";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
      if (*(params->pphDrivers) != nullptr) {
        str += " hDrivers = ";
        str += std::to_string((long long unsigned int)**(params->pphDrivers));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDriverGetApiVersionOnEnter(
    ze_driver_get_api_version_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDriverGetApiVersion:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " version = " + std::to_string((long long unsigned int)*(params->pversion));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDriverGetApiVersionOnExit(
    ze_driver_get_api_version_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDriverGetApiVersion";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDriverGetPropertiesOnEnter(
    ze_driver_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDriverGetProperties:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " pDriverProperties = " + std::to_string((long long unsigned int)*(params->ppDriverProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDriverGetPropertiesOnExit(
    ze_driver_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDriverGetProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDriverGetIpcPropertiesOnEnter(
    ze_driver_get_ipc_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDriverGetIpcProperties:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " pIpcProperties = " + std::to_string((long long unsigned int)*(params->ppIpcProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDriverGetIpcPropertiesOnExit(
    ze_driver_get_ipc_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDriverGetIpcProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDriverGetExtensionPropertiesOnEnter(
    ze_driver_get_extension_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDriverGetExtensionProperties:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " pExtensionProperties = " + std::to_string((long long unsigned int)*(params->ppExtensionProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDriverGetExtensionPropertiesOnExit(
    ze_driver_get_extension_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDriverGetExtensionProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetOnEnter(
    ze_device_get_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGet:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " phDevices = " + std::to_string((long long unsigned int)*(params->pphDevices));
    if (*(params->pphDevices) != nullptr) {
      str += " (hDevices = " + std::to_string((long long unsigned int)**(params->pphDevices)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetOnExit(
    ze_device_get_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGet";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
      if (*(params->pphDevices) != nullptr &&
          *(params->ppCount) != nullptr) {
        for (uint32_t i = 0; i < **(params->ppCount); ++i) {
          str += " hDevices[";
          str += std::to_string(i);
          str += "] = ";
            (*(params->pphDevices))[i];
        }
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetSubDevicesOnEnter(
    ze_device_get_sub_devices_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetSubDevices:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " phSubdevices = " + std::to_string((long long unsigned int)*(params->pphSubdevices));
    if (*(params->pphSubdevices) != nullptr) {
      str += " (hSubdevices = " + std::to_string((long long unsigned int)**(params->pphSubdevices)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetSubDevicesOnExit(
    ze_device_get_sub_devices_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetSubDevices";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
      if (*(params->pphSubdevices) != nullptr &&
          *(params->ppCount) != nullptr) {
        for (uint32_t i = 0; i < **(params->ppCount); ++i) {
          str += " hSubdevices[";
          str += std::to_string(i);
          str += "] = ";
            (*(params->pphSubdevices))[i];
        }
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetPropertiesOnEnter(
    ze_device_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pDeviceProperties = " + std::to_string((long long unsigned int)*(params->ppDeviceProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetPropertiesOnExit(
    ze_device_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetComputePropertiesOnEnter(
    ze_device_get_compute_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetComputeProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pComputeProperties = " + std::to_string((long long unsigned int)*(params->ppComputeProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetComputePropertiesOnExit(
    ze_device_get_compute_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetComputeProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetModulePropertiesOnEnter(
    ze_device_get_module_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetModuleProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pModuleProperties = " + std::to_string((long long unsigned int)*(params->ppModuleProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetModulePropertiesOnExit(
    ze_device_get_module_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetModuleProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetCommandQueueGroupPropertiesOnEnter(
    ze_device_get_command_queue_group_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetCommandQueueGroupProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " pCommandQueueGroupProperties = " + std::to_string((long long unsigned int)*(params->ppCommandQueueGroupProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetCommandQueueGroupPropertiesOnExit(
    ze_device_get_command_queue_group_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetCommandQueueGroupProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetMemoryPropertiesOnEnter(
    ze_device_get_memory_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetMemoryProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " pMemProperties = " + std::to_string((long long unsigned int)*(params->ppMemProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetMemoryPropertiesOnExit(
    ze_device_get_memory_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetMemoryProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetMemoryAccessPropertiesOnEnter(
    ze_device_get_memory_access_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetMemoryAccessProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pMemAccessProperties = " + std::to_string((long long unsigned int)*(params->ppMemAccessProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetMemoryAccessPropertiesOnExit(
    ze_device_get_memory_access_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetMemoryAccessProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetCachePropertiesOnEnter(
    ze_device_get_cache_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetCacheProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " pCacheProperties = " + std::to_string((long long unsigned int)*(params->ppCacheProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetCachePropertiesOnExit(
    ze_device_get_cache_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetCacheProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetImagePropertiesOnEnter(
    ze_device_get_image_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetImageProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pImageProperties = " + std::to_string((long long unsigned int)*(params->ppImageProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetImagePropertiesOnExit(
    ze_device_get_image_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetImageProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetExternalMemoryPropertiesOnEnter(
    ze_device_get_external_memory_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetExternalMemoryProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pExternalMemoryProperties = " + std::to_string((long long unsigned int)*(params->ppExternalMemoryProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetExternalMemoryPropertiesOnExit(
    ze_device_get_external_memory_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetExternalMemoryProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetP2PPropertiesOnEnter(
    ze_device_get_p2_p_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetP2PProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " hPeerDevice = " + std::to_string((long long unsigned int)*(params->phPeerDevice));
    str += " pP2PProperties = " + std::to_string((long long unsigned int)*(params->ppP2PProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetP2PPropertiesOnExit(
    ze_device_get_p2_p_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetP2PProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceCanAccessPeerOnEnter(
    ze_device_can_access_peer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceCanAccessPeer:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " hPeerDevice = " + std::to_string((long long unsigned int)*(params->phPeerDevice));
    str += " value = " + std::to_string((long long unsigned int)*(params->pvalue));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceCanAccessPeerOnExit(
    ze_device_can_access_peer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceCanAccessPeer";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeDeviceGetStatusOnEnter(
    ze_device_get_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeDeviceGetStatus:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeDeviceGetStatusOnExit(
    ze_device_get_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeDeviceGetStatus";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextCreateOnEnter(
    ze_context_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextCreate:";
    str += " hDriver = " + std::to_string((long long unsigned int)*(params->phDriver));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phContext = " + std::to_string((long long unsigned int)*(params->pphContext));
    if (*(params->pphContext) != nullptr) {
      str += " (hContext = " + std::to_string((long long unsigned int)**(params->pphContext)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextCreateOnExit(
    ze_context_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphContext) != nullptr) {
        str += " hContext = ";
        str += std::to_string((long long unsigned int)**(params->pphContext));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextDestroyOnEnter(
    ze_context_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextDestroy:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextDestroyOnExit(
    ze_context_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextGetStatusOnEnter(
    ze_context_get_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextGetStatus:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextGetStatusOnExit(
    ze_context_get_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextGetStatus";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextSystemBarrierOnEnter(
    ze_context_system_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextSystemBarrier:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextSystemBarrierOnExit(
    ze_context_system_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextSystemBarrier";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextMakeMemoryResidentOnEnter(
    ze_context_make_memory_resident_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextMakeMemoryResident:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextMakeMemoryResidentOnExit(
    ze_context_make_memory_resident_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextMakeMemoryResident";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextEvictMemoryOnEnter(
    ze_context_evict_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextEvictMemory:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextEvictMemoryOnExit(
    ze_context_evict_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextEvictMemory";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextMakeImageResidentOnEnter(
    ze_context_make_image_resident_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextMakeImageResident:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " hImage = " + std::to_string((long long unsigned int)*(params->phImage));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextMakeImageResidentOnExit(
    ze_context_make_image_resident_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextMakeImageResident";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeContextEvictImageOnEnter(
    ze_context_evict_image_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeContextEvictImage:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " hImage = " + std::to_string((long long unsigned int)*(params->phImage));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeContextEvictImageOnExit(
    ze_context_evict_image_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeContextEvictImage";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandQueueCreateOnEnter(
    ze_command_queue_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandQueueCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phCommandQueue = " + std::to_string((long long unsigned int)*(params->pphCommandQueue));
    if (*(params->pphCommandQueue) != nullptr) {
      str += " (hCommandQueue = " + std::to_string((long long unsigned int)**(params->pphCommandQueue)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandQueueCreateOnExit(
    ze_command_queue_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandQueueCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphCommandQueue) != nullptr) {
        str += " hCommandQueue = ";
        str += std::to_string((long long unsigned int)**(params->pphCommandQueue));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandQueueDestroyOnEnter(
    ze_command_queue_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandQueueDestroy:";
    str += " hCommandQueue = " + std::to_string((long long unsigned int)*(params->phCommandQueue));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandQueueDestroyOnExit(
    ze_command_queue_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandQueueDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandQueueExecuteCommandListsOnEnter(
    ze_command_queue_execute_command_lists_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandQueueExecuteCommandLists:";
    str += " hCommandQueue = " + std::to_string((long long unsigned int)*(params->phCommandQueue));
    str += " numCommandLists = " + std::to_string((long long unsigned int)*(params->pnumCommandLists));
    str += " phCommandLists = " + std::to_string((long long unsigned int)*(params->pphCommandLists));
    if (*(params->pphCommandLists) != nullptr) {
      str += " (hCommandLists = " + std::to_string((long long unsigned int)**(params->pphCommandLists)) + ")";
    }
    str += " hFence = " + std::to_string((long long unsigned int)*(params->phFence));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandQueueExecuteCommandListsOnExit(
    ze_command_queue_execute_command_lists_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandQueueExecuteCommandLists";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphCommandLists) != nullptr) {
        str += " hCommandLists = ";
        str += std::to_string((long long unsigned int)**(params->pphCommandLists));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandQueueSynchronizeOnEnter(
    ze_command_queue_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandQueueSynchronize:";
    str += " hCommandQueue = " + std::to_string((long long unsigned int)*(params->phCommandQueue));
    str += " timeout = " + std::to_string((long long unsigned int)*(params->ptimeout));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandQueueSynchronizeOnExit(
    ze_command_queue_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandQueueSynchronize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListCreateOnEnter(
    ze_command_list_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phCommandList = " + std::to_string((long long unsigned int)*(params->pphCommandList));
    if (*(params->pphCommandList) != nullptr) {
      str += " (hCommandList = " + std::to_string((long long unsigned int)**(params->pphCommandList)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListCreateOnExit(
    ze_command_list_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphCommandList) != nullptr) {
        str += " hCommandList = ";
        str += std::to_string((long long unsigned int)**(params->pphCommandList));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListCreateImmediateOnEnter(
    ze_command_list_create_immediate_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListCreateImmediate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " altdesc = " + std::to_string((long long unsigned int)*(params->paltdesc));
    str += " phCommandList = " + std::to_string((long long unsigned int)*(params->pphCommandList));
    if (*(params->pphCommandList) != nullptr) {
      str += " (hCommandList = " + std::to_string((long long unsigned int)**(params->pphCommandList)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListCreateImmediateOnExit(
    ze_command_list_create_immediate_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListCreateImmediate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphCommandList) != nullptr) {
        str += " hCommandList = ";
        str += std::to_string((long long unsigned int)**(params->pphCommandList));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListDestroyOnEnter(
    ze_command_list_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListDestroy:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListDestroyOnExit(
    ze_command_list_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListCloseOnEnter(
    ze_command_list_close_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListClose:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListCloseOnExit(
    ze_command_list_close_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListClose";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListResetOnEnter(
    ze_command_list_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListReset:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListResetOnExit(
    ze_command_list_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListReset";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendWriteGlobalTimestampOnEnter(
    ze_command_list_append_write_global_timestamp_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendWriteGlobalTimestamp:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendWriteGlobalTimestampOnExit(
    ze_command_list_append_write_global_timestamp_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendWriteGlobalTimestamp";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendBarrierOnEnter(
    ze_command_list_append_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendBarrier:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendBarrierOnExit(
    ze_command_list_append_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendBarrier";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryRangesBarrierOnEnter(
    ze_command_list_append_memory_ranges_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryRangesBarrier:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " numRanges = " + std::to_string((long long unsigned int)*(params->pnumRanges));
    str += " pRangeSizes = " + std::to_string((long long unsigned int)*(params->ppRangeSizes));
    str += " pRanges = " + std::to_string((long long unsigned int)*(params->ppRanges));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryRangesBarrierOnExit(
    ze_command_list_append_memory_ranges_barrier_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryRangesBarrier";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryCopyOnEnter(
    ze_command_list_append_memory_copy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryCopy:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " srcptr = " + std::to_string((long long unsigned int)*(params->psrcptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryCopyOnExit(
    ze_command_list_append_memory_copy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryCopy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryFillOnEnter(
    ze_command_list_append_memory_fill_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryFill:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " pattern = " + std::to_string((long long unsigned int)*(params->ppattern));
    str += " pattern_size = " + std::to_string((long long unsigned int)*(params->ppattern_size));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryFillOnExit(
    ze_command_list_append_memory_fill_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryFill";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryCopyRegionOnEnter(
    ze_command_list_append_memory_copy_region_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryCopyRegion:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " dstRegion = " + std::to_string((long long unsigned int)*(params->pdstRegion));
    str += " dstPitch = " + std::to_string((long long unsigned int)*(params->pdstPitch));
    str += " dstSlicePitch = " + std::to_string((long long unsigned int)*(params->pdstSlicePitch));
    str += " srcptr = " + std::to_string((long long unsigned int)*(params->psrcptr));
    str += " srcRegion = " + std::to_string((long long unsigned int)*(params->psrcRegion));
    str += " srcPitch = " + std::to_string((long long unsigned int)*(params->psrcPitch));
    str += " srcSlicePitch = " + std::to_string((long long unsigned int)*(params->psrcSlicePitch));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryCopyRegionOnExit(
    ze_command_list_append_memory_copy_region_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryCopyRegion";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryCopyFromContextOnEnter(
    ze_command_list_append_memory_copy_from_context_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryCopyFromContext:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " hContextSrc = " + std::to_string((long long unsigned int)*(params->phContextSrc));
    str += " srcptr = " + std::to_string((long long unsigned int)*(params->psrcptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryCopyFromContextOnExit(
    ze_command_list_append_memory_copy_from_context_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryCopyFromContext";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendImageCopyOnEnter(
    ze_command_list_append_image_copy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendImageCopy:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hDstImage = " + std::to_string((long long unsigned int)*(params->phDstImage));
    str += " hSrcImage = " + std::to_string((long long unsigned int)*(params->phSrcImage));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendImageCopyOnExit(
    ze_command_list_append_image_copy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendImageCopy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendImageCopyRegionOnEnter(
    ze_command_list_append_image_copy_region_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendImageCopyRegion:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hDstImage = " + std::to_string((long long unsigned int)*(params->phDstImage));
    str += " hSrcImage = " + std::to_string((long long unsigned int)*(params->phSrcImage));
    str += " pDstRegion = " + std::to_string((long long unsigned int)*(params->ppDstRegion));
    str += " pSrcRegion = " + std::to_string((long long unsigned int)*(params->ppSrcRegion));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendImageCopyRegionOnExit(
    ze_command_list_append_image_copy_region_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendImageCopyRegion";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendImageCopyToMemoryOnEnter(
    ze_command_list_append_image_copy_to_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendImageCopyToMemory:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " hSrcImage = " + std::to_string((long long unsigned int)*(params->phSrcImage));
    str += " pSrcRegion = " + std::to_string((long long unsigned int)*(params->ppSrcRegion));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendImageCopyToMemoryOnExit(
    ze_command_list_append_image_copy_to_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendImageCopyToMemory";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendImageCopyFromMemoryOnEnter(
    ze_command_list_append_image_copy_from_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendImageCopyFromMemory:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hDstImage = " + std::to_string((long long unsigned int)*(params->phDstImage));
    str += " srcptr = " + std::to_string((long long unsigned int)*(params->psrcptr));
    str += " pDstRegion = " + std::to_string((long long unsigned int)*(params->ppDstRegion));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendImageCopyFromMemoryOnExit(
    ze_command_list_append_image_copy_from_memory_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendImageCopyFromMemory";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemoryPrefetchOnEnter(
    ze_command_list_append_memory_prefetch_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemoryPrefetch:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemoryPrefetchOnExit(
    ze_command_list_append_memory_prefetch_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemoryPrefetch";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendMemAdviseOnEnter(
    ze_command_list_append_mem_advise_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendMemAdvise:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " advice = " + std::to_string((long long unsigned int)*(params->padvice));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendMemAdviseOnExit(
    ze_command_list_append_mem_advise_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendMemAdvise";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendSignalEventOnEnter(
    ze_command_list_append_signal_event_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendSignalEvent:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendSignalEventOnExit(
    ze_command_list_append_signal_event_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendSignalEvent";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendWaitOnEventsOnEnter(
    ze_command_list_append_wait_on_events_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendWaitOnEvents:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " numEvents = " + std::to_string((long long unsigned int)*(params->pnumEvents));
    str += " phEvents = " + std::to_string((long long unsigned int)*(params->pphEvents));
    if (*(params->pphEvents) != nullptr) {
      str += " (hEvents = [";
      auto phWaitEvents = *(params->pphEvents);
      auto numWaitEvents = *(params->pnumEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendWaitOnEventsOnExit(
    ze_command_list_append_wait_on_events_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendWaitOnEvents";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphEvents) != nullptr) {
        str += " hEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendEventResetOnEnter(
    ze_command_list_append_event_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendEventReset:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendEventResetOnExit(
    ze_command_list_append_event_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendEventReset";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendQueryKernelTimestampsOnEnter(
    ze_command_list_append_query_kernel_timestamps_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendQueryKernelTimestamps:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " numEvents = " + std::to_string((long long unsigned int)*(params->pnumEvents));
    str += " phEvents = " + std::to_string((long long unsigned int)*(params->pphEvents));
    if (*(params->pphEvents) != nullptr) {
      str += " (hEvents = [";
      auto phWaitEvents = *(params->pphEvents);
      auto numWaitEvents = *(params->pnumEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += " pOffsets = " + std::to_string((long long unsigned int)*(params->ppOffsets));
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendQueryKernelTimestampsOnExit(
    ze_command_list_append_query_kernel_timestamps_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendQueryKernelTimestamps";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphEvents) != nullptr) {
        str += " hEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphEvents));
      }
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendLaunchKernelOnEnter(
    ze_command_list_append_launch_kernel_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendLaunchKernel:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pLaunchFuncArgs = " + std::to_string((long long unsigned int)*(params->ppLaunchFuncArgs));
    if (*(params->ppLaunchFuncArgs) != nullptr) {
      str += " {" + std::to_string((*(params->ppLaunchFuncArgs))->groupCountX) + ", ";
      str += std::to_string((*(params->ppLaunchFuncArgs))->groupCountY) + ", ";
      str += std::to_string((*(params->ppLaunchFuncArgs))->groupCountZ) + "}";
    }
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendLaunchKernelOnExit(
    ze_command_list_append_launch_kernel_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendLaunchKernel";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendLaunchCooperativeKernelOnEnter(
    ze_command_list_append_launch_cooperative_kernel_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendLaunchCooperativeKernel:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pLaunchFuncArgs = " + std::to_string((long long unsigned int)*(params->ppLaunchFuncArgs));
    if (*(params->ppLaunchFuncArgs) != nullptr) {
      str += " {" + std::to_string((*(params->ppLaunchFuncArgs))->groupCountX) + ", ";
      str += std::to_string((*(params->ppLaunchFuncArgs))->groupCountY) + ", ";
      str += std::to_string((*(params->ppLaunchFuncArgs))->groupCountZ) + "}";
    }
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendLaunchCooperativeKernelOnExit(
    ze_command_list_append_launch_cooperative_kernel_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendLaunchCooperativeKernel";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendLaunchKernelIndirectOnEnter(
    ze_command_list_append_launch_kernel_indirect_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendLaunchKernelIndirect:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pLaunchArgumentsBuffer = " + std::to_string((long long unsigned int)*(params->ppLaunchArgumentsBuffer));
    if (*(params->ppLaunchArgumentsBuffer) != nullptr) {
      str += " {" + std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountX) + ", ";
      str += std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountY) + ", ";
      str += std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountZ) + "}";
    }
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendLaunchKernelIndirectOnExit(
    ze_command_list_append_launch_kernel_indirect_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendLaunchKernelIndirect";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeCommandListAppendLaunchMultipleKernelsIndirectOnEnter(
    ze_command_list_append_launch_multiple_kernels_indirect_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeCommandListAppendLaunchMultipleKernelsIndirect:";
    str += " hCommandList = " + std::to_string((long long unsigned int)*(params->phCommandList));
    str += " numKernels = " + std::to_string((long long unsigned int)*(params->pnumKernels));
    str += " phKernels = " + std::to_string((long long unsigned int)*(params->pphKernels));
    if (*(params->pphKernels) != nullptr) {
      str += " (hKernels = " + std::to_string((long long unsigned int)**(params->pphKernels)) + ")";
    }
    str += " pCountBuffer = " + std::to_string((long long unsigned int)*(params->ppCountBuffer));
    if (*(params->ppCountBuffer) != nullptr) {
      str += " (CountBuffer = " + std::to_string((long long unsigned int)**(params->ppCountBuffer)) + ")";
    }
    str += " pLaunchArgumentsBuffer = " + std::to_string((long long unsigned int)*(params->ppLaunchArgumentsBuffer));
    if (*(params->ppLaunchArgumentsBuffer) != nullptr) {
      str += " {" + std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountX) + ", ";
      str += std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountY) + ", ";
      str += std::to_string((*(params->ppLaunchArgumentsBuffer))->groupCountZ) + "}";
    }
    str += " hSignalEvent = " + std::to_string((long long unsigned int)*(params->phSignalEvent));
    str += " numWaitEvents = " + std::to_string((long long unsigned int)*(params->pnumWaitEvents));
    str += " phWaitEvents = " + std::to_string((long long unsigned int)*(params->pphWaitEvents));
    if (*(params->pphWaitEvents) != nullptr) {
      str += " (hWaitEvents = [";
      auto phWaitEvents = *(params->pphWaitEvents);
      auto numWaitEvents = *(params->pnumWaitEvents);
      while(numWaitEvents > 0) {
        str += std::to_string((long int)*phWaitEvents);
        numWaitEvents--;
        if (numWaitEvents > 0)
          str +=", ";
        phWaitEvents = phWaitEvents + 1;
      }
      str += "])";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeCommandListAppendLaunchMultipleKernelsIndirectOnExit(
    ze_command_list_append_launch_multiple_kernels_indirect_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeCommandListAppendLaunchMultipleKernelsIndirect";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphKernels) != nullptr) {
        str += " hKernels = ";
        str += std::to_string((long long unsigned int)**(params->pphKernels));
      }
      if (*(params->pphWaitEvents) != nullptr) {
        str += " hWaitEvents = ";
        str += std::to_string((long long unsigned int)**(params->pphWaitEvents));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeImageGetPropertiesOnEnter(
    ze_image_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeImageGetProperties:";
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " pImageProperties = " + std::to_string((long long unsigned int)*(params->ppImageProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeImageGetPropertiesOnExit(
    ze_image_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeImageGetProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeImageCreateOnEnter(
    ze_image_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeImageCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phImage = " + std::to_string((long long unsigned int)*(params->pphImage));
    if (*(params->pphImage) != nullptr) {
      str += " (hImage = " + std::to_string((long long unsigned int)**(params->pphImage)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeImageCreateOnExit(
    ze_image_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeImageCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphImage) != nullptr) {
        str += " hImage = ";
        str += std::to_string((long long unsigned int)**(params->pphImage));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeImageDestroyOnEnter(
    ze_image_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeImageDestroy:";
    str += " hImage = " + std::to_string((long long unsigned int)*(params->phImage));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeImageDestroyOnExit(
    ze_image_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeImageDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeFenceCreateOnEnter(
    ze_fence_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeFenceCreate:";
    str += " hCommandQueue = " + std::to_string((long long unsigned int)*(params->phCommandQueue));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phFence = " + std::to_string((long long unsigned int)*(params->pphFence));
    if (*(params->pphFence) != nullptr) {
      str += " (hFence = " + std::to_string((long long unsigned int)**(params->pphFence)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeFenceCreateOnExit(
    ze_fence_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeFenceCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphFence) != nullptr) {
        str += " hFence = ";
        str += std::to_string((long long unsigned int)**(params->pphFence));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeFenceDestroyOnEnter(
    ze_fence_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeFenceDestroy:";
    str += " hFence = " + std::to_string((long long unsigned int)*(params->phFence));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeFenceDestroyOnExit(
    ze_fence_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeFenceDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeFenceHostSynchronizeOnEnter(
    ze_fence_host_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeFenceHostSynchronize:";
    str += " hFence = " + std::to_string((long long unsigned int)*(params->phFence));
    str += " timeout = " + std::to_string((long long unsigned int)*(params->ptimeout));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeFenceHostSynchronizeOnExit(
    ze_fence_host_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeFenceHostSynchronize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeFenceQueryStatusOnEnter(
    ze_fence_query_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeFenceQueryStatus:";
    str += " hFence = " + std::to_string((long long unsigned int)*(params->phFence));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeFenceQueryStatusOnExit(
    ze_fence_query_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeFenceQueryStatus";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeFenceResetOnEnter(
    ze_fence_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeFenceReset:";
    str += " hFence = " + std::to_string((long long unsigned int)*(params->phFence));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeFenceResetOnExit(
    ze_fence_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeFenceReset";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventPoolCreateOnEnter(
    ze_event_pool_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventPoolCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    if (*(params->pdesc) != nullptr) {
      str += " {";
      str += GetStructureTypeString((*(params->pdesc))->stype);
      std::stringstream hexstream;      hexstream << std::hex << (*(params->pdesc))->stype;      str += "(0x"+ hexstream.str() + ") ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->pNext) + " ";
      str += std::to_string((*(params->pdesc))->flags) + " ";
      str += std::to_string((*(params->pdesc))->count) + "}";
    }
    str += " numDevices = " + std::to_string((long long unsigned int)*(params->pnumDevices));
    str += " phDevices = " + std::to_string((long long unsigned int)*(params->pphDevices));
    if (*(params->pphDevices) != nullptr) {
      str += " (hDevices = " + std::to_string((long long unsigned int)**(params->pphDevices)) + ")";
    }
    str += " phEventPool = " + std::to_string((long long unsigned int)*(params->pphEventPool));
    if (*(params->pphEventPool) != nullptr) {
      str += " (hEventPool = " + std::to_string((long long unsigned int)**(params->pphEventPool)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventPoolCreateOnExit(
    ze_event_pool_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventPoolCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphDevices) != nullptr) {
        str += " hDevices = ";
        str += std::to_string((long long unsigned int)**(params->pphDevices));
      }
      if (*(params->pphEventPool) != nullptr) {
        str += " hEventPool = ";
        str += std::to_string((long long unsigned int)**(params->pphEventPool));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventPoolDestroyOnEnter(
    ze_event_pool_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventPoolDestroy:";
    str += " hEventPool = " + std::to_string((long long unsigned int)*(params->phEventPool));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventPoolDestroyOnExit(
    ze_event_pool_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventPoolDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventPoolGetIpcHandleOnEnter(
    ze_event_pool_get_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventPoolGetIpcHandle:";
    str += " hEventPool = " + std::to_string((long long unsigned int)*(params->phEventPool));
    str += " phIpc = " + std::to_string((long long unsigned int)*(params->pphIpc));
    if (*(params->pphIpc) != nullptr) {
      str += " (hIpc = " + std::to_string((long long unsigned int)(*(params->pphIpc))->data);
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventPoolGetIpcHandleOnExit(
    ze_event_pool_get_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventPoolGetIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphIpc) != nullptr) {
        str += " hIpc = ";
        str += (*(params->pphIpc))->data;
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventPoolOpenIpcHandleOnEnter(
    ze_event_pool_open_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventPoolOpenIpcHandle:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hIpc = " + std::to_string((long long unsigned int)(params->phIpc)->data);
    str += " phEventPool = " + std::to_string((long long unsigned int)*(params->pphEventPool));
    if (*(params->pphEventPool) != nullptr) {
      str += " (hEventPool = " + std::to_string((long long unsigned int)**(params->pphEventPool)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventPoolOpenIpcHandleOnExit(
    ze_event_pool_open_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventPoolOpenIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphEventPool) != nullptr) {
        str += " hEventPool = ";
        str += std::to_string((long long unsigned int)**(params->pphEventPool));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventPoolCloseIpcHandleOnEnter(
    ze_event_pool_close_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventPoolCloseIpcHandle:";
    str += " hEventPool = " + std::to_string((long long unsigned int)*(params->phEventPool));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventPoolCloseIpcHandleOnExit(
    ze_event_pool_close_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventPoolCloseIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventCreateOnEnter(
    ze_event_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventCreate:";
    str += " hEventPool = " + std::to_string((long long unsigned int)*(params->phEventPool));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phEvent = " + std::to_string((long long unsigned int)*(params->pphEvent));
    if (*(params->pphEvent) != nullptr) {
      str += " (hEvent = " + std::to_string((long long unsigned int)**(params->pphEvent)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventCreateOnExit(
    ze_event_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphEvent) != nullptr) {
        str += " hEvent = ";
        str += std::to_string((long long unsigned int)**(params->pphEvent));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventDestroyOnEnter(
    ze_event_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventDestroy:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventDestroyOnExit(
    ze_event_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventHostSignalOnEnter(
    ze_event_host_signal_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventHostSignal:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventHostSignalOnExit(
    ze_event_host_signal_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventHostSignal";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventHostSynchronizeOnEnter(
    ze_event_host_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventHostSynchronize:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += " timeout = " + std::to_string((long long unsigned int)*(params->ptimeout));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventHostSynchronizeOnExit(
    ze_event_host_synchronize_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventHostSynchronize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventQueryStatusOnEnter(
    ze_event_query_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventQueryStatus:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventQueryStatusOnExit(
    ze_event_query_status_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventQueryStatus";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventHostResetOnEnter(
    ze_event_host_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventHostReset:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventHostResetOnExit(
    ze_event_host_reset_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventHostReset";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeEventQueryKernelTimestampOnEnter(
    ze_event_query_kernel_timestamp_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeEventQueryKernelTimestamp:";
    str += " hEvent = " + std::to_string((long long unsigned int)*(params->phEvent));
    str += " dstptr = " + std::to_string((long long unsigned int)*(params->pdstptr));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeEventQueryKernelTimestampOnExit(
    ze_event_query_kernel_timestamp_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeEventQueryKernelTimestamp";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleCreateOnEnter(
    ze_module_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    if (*(params->pdesc) != nullptr) {
      str += " {";
      str += GetStructureTypeString((*(params->pdesc))->stype);
      std::stringstream hexstream;      hexstream << std::hex << (*(params->pdesc))->stype;      str += "(0x"+ hexstream.str() + ") ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->pNext) + " ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->format) + " ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->inputSize) + " ";
      str += std::to_string((long long unsigned int)static_cast<const void*>((*(params->pdesc))->pInputModule)) + " ";
      if ((*(params->pdesc)) -> pBuildFlags != nullptr)
        str += std::to_string((long long unsigned int)(*(params->pdesc))->pBuildFlags) + " ";
      else str += "0 ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->pConstants) + "}";
    }
    str += " phModule = " + std::to_string((long long unsigned int)*(params->pphModule));
    if (*(params->pphModule) != nullptr) {
      str += " (hModule = " + std::to_string((long long unsigned int)**(params->pphModule)) + ")";
    }
    str += " phBuildLog = " + std::to_string((long long unsigned int)*(params->pphBuildLog));
    if (*(params->pphBuildLog) != nullptr) {
      str += " (hBuildLog = " + std::to_string((long long unsigned int)**(params->pphBuildLog)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleCreateOnExit(
    ze_module_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();
  if (collector->options_.kernel_tracing) { 
    OnExitModuleCreate(params, result, global_user_data, instance_user_data); 
  }


  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphModule) != nullptr) {
        str += " hModule = ";
        str += std::to_string((long long unsigned int)**(params->pphModule));
      }
      if (*(params->pphBuildLog) != nullptr) {
        str += " hBuildLog = ";
        str += std::to_string((long long unsigned int)**(params->pphBuildLog));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
    bool aot = (*(params->pdesc))->format; 
    unsigned int kcount = 0; 
    if (zeModuleGetKernelNames(**(params->pphModule), &kcount, NULL) == ZE_RESULT_SUCCESS) {
      if (aot) { 
        str += "AOT (AOT_BINARY) "; 
      }
      else {
        str += "JIT (IL_SPIRV) "; 
      }
      str += "kernels in module: " + std::to_string(kcount) + "\n";
    }
    char *p = (char *)malloc(kcount * 1024 + kcount * sizeof(char **));
    const char **knames = (const char **)p;
    char *q = p + kcount * sizeof(char **);
    for (int i = 0; i < kcount; i++) {
      knames[i] = q;
      q += 1024;
    }
    if (zeModuleGetKernelNames(**(params->pphModule), &kcount, knames) == ZE_RESULT_SUCCESS) {
      for (int i = 0; i < kcount; i++) {
        str += "Kernel #" + std::to_string(i) + ": " + knames[i] + "\n";
      }
    }
    free(p);
  }
}

static void zeModuleDestroyOnEnter(
    ze_module_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);

  if (collector->options_.kernel_tracing) { 
    OnEnterModuleDestroy(params, global_user_data, instance_user_data); 
  }


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleDestroy:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleDestroyOnExit(
    ze_module_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleDynamicLinkOnEnter(
    ze_module_dynamic_link_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleDynamicLink:";
    str += " numModules = " + std::to_string((long long unsigned int)*(params->pnumModules));
    str += " phModules = " + std::to_string((long long unsigned int)*(params->pphModules));
    if (*(params->pphModules) != nullptr) {
      str += " (hModules = " + std::to_string((long long unsigned int)**(params->pphModules)) + ")";
    }
    str += " phLinkLog = " + std::to_string((long long unsigned int)*(params->pphLinkLog));
    if (*(params->pphLinkLog) != nullptr) {
      str += " (hLinkLog = " + std::to_string((long long unsigned int)**(params->pphLinkLog)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleDynamicLinkOnExit(
    ze_module_dynamic_link_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleDynamicLink";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphModules) != nullptr) {
        str += " hModules = ";
        str += std::to_string((long long unsigned int)**(params->pphModules));
      }
      if (*(params->pphLinkLog) != nullptr) {
        str += " hLinkLog = ";
        str += std::to_string((long long unsigned int)**(params->pphLinkLog));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleGetNativeBinaryOnEnter(
    ze_module_get_native_binary_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleGetNativeBinary:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    str += " pModuleNativeBinary = " + std::to_string((long long unsigned int)*(params->ppModuleNativeBinary));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleGetNativeBinaryOnExit(
    ze_module_get_native_binary_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleGetNativeBinary";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleGetGlobalPointerOnEnter(
    ze_module_get_global_pointer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleGetGlobalPointer:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    if (*(params->ppGlobalName) == nullptr) {
      str += " pGlobalName = 0";
    } else if (strlen(*(params->ppGlobalName)) == 0) {
      str += " pGlobalName = \"\"";
    } else {
      str += " pGlobalName = \"" + std::string(*(params->ppGlobalName)) + "\"";
    }
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleGetGlobalPointerOnExit(
    ze_module_get_global_pointer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleGetGlobalPointer";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleGetKernelNamesOnEnter(
    ze_module_get_kernel_names_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleGetKernelNames:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    str += " pCount = " + std::to_string((long long unsigned int)*(params->ppCount));
    if (*(params->ppCount) != nullptr) {
      str += " (Count = " + std::to_string((long long unsigned int)**(params->ppCount)) + ")";
    }
    str += " pNames = " + std::to_string((long long unsigned int)*(params->ppNames));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleGetKernelNamesOnExit(
    ze_module_get_kernel_names_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleGetKernelNames";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppCount) != nullptr) {
        str += " Count = " + std::to_string((long long unsigned int)**(params->ppCount));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleGetPropertiesOnEnter(
    ze_module_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleGetProperties:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    str += " pModuleProperties = " + std::to_string((long long unsigned int)*(params->ppModuleProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleGetPropertiesOnExit(
    ze_module_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleGetProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleGetFunctionPointerOnEnter(
    ze_module_get_function_pointer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleGetFunctionPointer:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    if (*(params->ppFunctionName) == nullptr) {
      str += " pFunctionName = 0";
    } else if (strlen(*(params->ppFunctionName)) == 0) {
      str += " pFunctionName = \"\"";
    } else {
      str += " pFunctionName = \"" + std::string(*(params->ppFunctionName)) + "\"";
    }
    str += " pfnFunction = " + std::to_string((long long unsigned int)*(params->ppfnFunction));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleGetFunctionPointerOnExit(
    ze_module_get_function_pointer_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleGetFunctionPointer";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleBuildLogDestroyOnEnter(
    ze_module_build_log_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleBuildLogDestroy:";
    str += " hModuleBuildLog = " + std::to_string((long long unsigned int)*(params->phModuleBuildLog));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleBuildLogDestroyOnExit(
    ze_module_build_log_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleBuildLogDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeModuleBuildLogGetStringOnEnter(
    ze_module_build_log_get_string_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeModuleBuildLogGetString:";
    str += " hModuleBuildLog = " + std::to_string((long long unsigned int)*(params->phModuleBuildLog));
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    if (*(params->ppBuildLog) == nullptr) {
      str += " pBuildLog = 0";
    } else {
      str += " pBuildLog = ";
      str += std::to_string((long long unsigned int)*(params->ppBuildLog));
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeModuleBuildLogGetStringOnExit(
    ze_module_build_log_get_string_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeModuleBuildLogGetString";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelCreateOnEnter(
    ze_kernel_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelCreate:";
    str += " hModule = " + std::to_string((long long unsigned int)*(params->phModule));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    if (*(params->pdesc) != nullptr) {
      str += " {";
      str += GetStructureTypeString((*(params->pdesc))->stype);
      std::stringstream hexstream;      hexstream << std::hex << (*(params->pdesc))->stype;      str += "(0x"+ hexstream.str() + ") ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->pNext) + " ";
      str += std::to_string((*(params->pdesc))->flags) + " ";
      if ((*(params->pdesc))->pKernelName == nullptr) {
        str += "0";
      } else if (strlen((*(params->pdesc))->pKernelName) == 0) {
        str += " desc = \"\"";
      } else {
        str += "\"" + std::string((*(params->pdesc))->pKernelName) + "\"";
        if (collector->options_.demangle) {
          str += " (" + utils::Demangle((*(params->pdesc))->pKernelName) + ")";
        }
      str += "}";
      }
    }
    str += " phKernel = " + std::to_string((long long unsigned int)*(params->pphKernel));
    if (*(params->pphKernel) != nullptr) {
      str += " (hKernel = " + std::to_string((long long unsigned int)**(params->pphKernel)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelCreateOnExit(
    ze_kernel_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();
  if (collector->options_.kernel_tracing) { 
    OnExitKernelCreate(params, result, global_user_data, instance_user_data); 
  }


  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphKernel) != nullptr) {
        str += " hKernel = ";
        str += std::to_string((long long unsigned int)**(params->pphKernel));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelDestroyOnEnter(
    ze_kernel_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelDestroy:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelDestroyOnExit(
    ze_kernel_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSetCacheConfigOnEnter(
    ze_kernel_set_cache_config_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSetCacheConfig:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " flags = " + std::to_string((long long unsigned int)*(params->pflags));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSetCacheConfigOnExit(
    ze_kernel_set_cache_config_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSetCacheConfig";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSetGroupSizeOnEnter(
    ze_kernel_set_group_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSetGroupSize:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " groupSizeX = " + std::to_string((long long unsigned int)*(params->pgroupSizeX));
    str += " groupSizeY = " + std::to_string((long long unsigned int)*(params->pgroupSizeY));
    str += " groupSizeZ = " + std::to_string((long long unsigned int)*(params->pgroupSizeZ));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSetGroupSizeOnExit(
    ze_kernel_set_group_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSetGroupSize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSuggestGroupSizeOnEnter(
    ze_kernel_suggest_group_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSuggestGroupSize:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " globalSizeX = " + std::to_string((long long unsigned int)*(params->pglobalSizeX));
    str += " globalSizeY = " + std::to_string((long long unsigned int)*(params->pglobalSizeY));
    str += " globalSizeZ = " + std::to_string((long long unsigned int)*(params->pglobalSizeZ));
    str += " groupSizeX = " + std::to_string((long long unsigned int)*(params->pgroupSizeX));
    str += " groupSizeY = " + std::to_string((long long unsigned int)*(params->pgroupSizeY));
    str += " groupSizeZ = " + std::to_string((long long unsigned int)*(params->pgroupSizeZ));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSuggestGroupSizeOnExit(
    ze_kernel_suggest_group_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSuggestGroupSize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pgroupSizeX) != nullptr) {
        str += " groupSizeX = " + std::to_string((long long unsigned int)**(params->pgroupSizeX));
      }
      if (*(params->pgroupSizeY) != nullptr) {
        str += " groupSizeY = " + std::to_string((long long unsigned int)**(params->pgroupSizeY));
      }
      if (*(params->pgroupSizeZ) != nullptr) {
        str += " groupSizeZ = " + std::to_string((long long unsigned int)**(params->pgroupSizeZ));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSuggestMaxCooperativeGroupCountOnEnter(
    ze_kernel_suggest_max_cooperative_group_count_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSuggestMaxCooperativeGroupCount:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " totalGroupCount = " + std::to_string((long long unsigned int)*(params->ptotalGroupCount));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSuggestMaxCooperativeGroupCountOnExit(
    ze_kernel_suggest_max_cooperative_group_count_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSuggestMaxCooperativeGroupCount";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSetArgumentValueOnEnter(
    ze_kernel_set_argument_value_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSetArgumentValue:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " argIndex = " + std::to_string((long long unsigned int)*(params->pargIndex));
    str += " argSize = " + std::to_string((long long unsigned int)*(params->pargSize));
    str += " pArgValue = " + std::to_string((long long unsigned int)*(params->ppArgValue));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSetArgumentValueOnExit(
    ze_kernel_set_argument_value_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSetArgumentValue";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelSetIndirectAccessOnEnter(
    ze_kernel_set_indirect_access_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelSetIndirectAccess:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " flags = " + std::to_string((long long unsigned int)*(params->pflags));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelSetIndirectAccessOnExit(
    ze_kernel_set_indirect_access_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelSetIndirectAccess";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelGetIndirectAccessOnEnter(
    ze_kernel_get_indirect_access_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelGetIndirectAccess:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pFlags = " + std::to_string((long long unsigned int)*(params->ppFlags));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelGetIndirectAccessOnExit(
    ze_kernel_get_indirect_access_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelGetIndirectAccess";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelGetSourceAttributesOnEnter(
    ze_kernel_get_source_attributes_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelGetSourceAttributes:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    str += " pString = " + std::to_string((long long unsigned int)*(params->ppString));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelGetSourceAttributesOnExit(
    ze_kernel_get_source_attributes_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelGetSourceAttributes";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelGetPropertiesOnEnter(
    ze_kernel_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelGetProperties:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pKernelProperties = " + std::to_string((long long unsigned int)*(params->ppKernelProperties));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelGetPropertiesOnExit(
    ze_kernel_get_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelGetProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeKernelGetNameOnEnter(
    ze_kernel_get_name_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeKernelGetName:";
    str += " hKernel = " + std::to_string((long long unsigned int)*(params->phKernel));
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    if (*(params->ppName) == nullptr) {
      str += " pName = 0";
    } else {
      str += " pName = ";
      str += std::to_string((long long unsigned int)*(params->ppName));
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeKernelGetNameOnExit(
    ze_kernel_get_name_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeKernelGetName";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
      if (*(params->ppName) != nullptr) {
        if (strlen(*(params->ppName)) == 0) {
          str += " Name = \"\"";
        } else {
          str += " Name = \"";
          str += std::to_string((long long unsigned int)*(params->ppName));
          str += "\"";
        }
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeSamplerCreateOnEnter(
    ze_sampler_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeSamplerCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    if (*(params->pdesc) != nullptr) {
      str += " {";
      str += GetStructureTypeString((*(params->pdesc))->stype);
      std::stringstream hexstream;      hexstream << std::hex << (*(params->pdesc))->stype;      str += "(0x"+ hexstream.str() + ") ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->pNext) + " ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->addressMode) + " ";
      str += std::to_string((long long unsigned int)(*(params->pdesc))->filterMode) + " ";
      str += std::to_string((long long unsigned int)static_cast<const unsigned char>((*(params->pdesc))->isNormalized)) + "}";
    }
    str += " phSampler = " + std::to_string((long long unsigned int)*(params->pphSampler));
    if (*(params->pphSampler) != nullptr) {
      str += " (hSampler = " + std::to_string((long long unsigned int)**(params->pphSampler)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeSamplerCreateOnExit(
    ze_sampler_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeSamplerCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphSampler) != nullptr) {
        str += " hSampler = ";
        str += std::to_string((long long unsigned int)**(params->pphSampler));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeSamplerDestroyOnEnter(
    ze_sampler_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeSamplerDestroy:";
    str += " hSampler = " + std::to_string((long long unsigned int)*(params->phSampler));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeSamplerDestroyOnExit(
    ze_sampler_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeSamplerDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zePhysicalMemCreateOnEnter(
    ze_physical_mem_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zePhysicalMemCreate:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " desc = " + std::to_string((long long unsigned int)*(params->pdesc));
    str += " phPhysicalMemory = " + std::to_string((long long unsigned int)*(params->pphPhysicalMemory));
    if (*(params->pphPhysicalMemory) != nullptr) {
      str += " (hPhysicalMemory = " + std::to_string((long long unsigned int)**(params->pphPhysicalMemory)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zePhysicalMemCreateOnExit(
    ze_physical_mem_create_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zePhysicalMemCreate";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphPhysicalMemory) != nullptr) {
        str += " hPhysicalMemory = ";
        str += std::to_string((long long unsigned int)**(params->pphPhysicalMemory));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zePhysicalMemDestroyOnEnter(
    ze_physical_mem_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zePhysicalMemDestroy:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hPhysicalMemory = " + std::to_string((long long unsigned int)*(params->phPhysicalMemory));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zePhysicalMemDestroyOnExit(
    ze_physical_mem_destroy_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zePhysicalMemDestroy";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemAllocSharedOnEnter(
    ze_mem_alloc_shared_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemAllocShared:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " device_desc = " + std::to_string((long long unsigned int)*(params->pdevice_desc));
    str += " host_desc = " + std::to_string((long long unsigned int)*(params->phost_desc));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " alignment = " + std::to_string((long long unsigned int)*(params->palignment));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemAllocSharedOnExit(
    ze_mem_alloc_shared_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemAllocShared";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemAllocDeviceOnEnter(
    ze_mem_alloc_device_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemAllocDevice:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " device_desc = " + std::to_string((long long unsigned int)*(params->pdevice_desc));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " alignment = " + std::to_string((long long unsigned int)*(params->palignment));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemAllocDeviceOnExit(
    ze_mem_alloc_device_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemAllocDevice";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemAllocHostOnEnter(
    ze_mem_alloc_host_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemAllocHost:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " host_desc = " + std::to_string((long long unsigned int)*(params->phost_desc));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " alignment = " + std::to_string((long long unsigned int)*(params->palignment));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemAllocHostOnExit(
    ze_mem_alloc_host_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemAllocHost";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemFreeOnEnter(
    ze_mem_free_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemFree:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemFreeOnExit(
    ze_mem_free_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemFree";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemGetAllocPropertiesOnEnter(
    ze_mem_get_alloc_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemGetAllocProperties:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " pMemAllocProperties = " + std::to_string((long long unsigned int)*(params->ppMemAllocProperties));
    str += " phDevice = " + std::to_string((long long unsigned int)*(params->pphDevice));
    if (*(params->pphDevice) != nullptr) {
      str += " (hDevice = " + std::to_string((long long unsigned int)**(params->pphDevice)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemGetAllocPropertiesOnExit(
    ze_mem_get_alloc_properties_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemGetAllocProperties";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->pphDevice) != nullptr) {
        str += " hDevice = ";
        str += std::to_string((long long unsigned int)**(params->pphDevice));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemGetAddressRangeOnEnter(
    ze_mem_get_address_range_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemGetAddressRange:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " pBase = " + std::to_string((long long unsigned int)*(params->ppBase));
    str += " pSize = " + std::to_string((long long unsigned int)*(params->ppSize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemGetAddressRangeOnExit(
    ze_mem_get_address_range_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemGetAddressRange";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppSize) != nullptr) {
        str += " Size = " + std::to_string((long long unsigned int)**(params->ppSize));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemGetIpcHandleOnEnter(
    ze_mem_get_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemGetIpcHandle:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " pIpcHandle = " + std::to_string((long long unsigned int)*(params->ppIpcHandle));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemGetIpcHandleOnExit(
    ze_mem_get_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemGetIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemOpenIpcHandleOnEnter(
    ze_mem_open_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemOpenIpcHandle:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " handle = " + std::to_string((long long unsigned int)(params->phandle)->data);
    str += " flags = " + std::to_string((long long unsigned int)*(params->pflags));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemOpenIpcHandleOnExit(
    ze_mem_open_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemOpenIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeMemCloseIpcHandleOnEnter(
    ze_mem_close_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeMemCloseIpcHandle:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeMemCloseIpcHandleOnExit(
    ze_mem_close_ipc_handle_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeMemCloseIpcHandle";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemReserveOnEnter(
    ze_virtual_mem_reserve_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemReserve:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " pStart = " + std::to_string((long long unsigned int)*(params->ppStart));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " pptr = " + std::to_string((long long unsigned int)*(params->ppptr));
    if (*(params->ppptr) != nullptr) {
      str += " (ptr = " + std::to_string((long long unsigned int)**(params->ppptr)) + ")";
    }
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemReserveOnExit(
    ze_virtual_mem_reserve_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemReserve";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
      if (*(params->ppptr) != nullptr) {
        str += " ptr = " + std::to_string((long long unsigned int)**(params->ppptr));
      }
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemFreeOnEnter(
    ze_virtual_mem_free_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemFree:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemFreeOnExit(
    ze_virtual_mem_free_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemFree";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemQueryPageSizeOnEnter(
    ze_virtual_mem_query_page_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemQueryPageSize:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " hDevice = " + std::to_string((long long unsigned int)*(params->phDevice));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " pagesize = " + std::to_string((long long unsigned int)*(params->ppagesize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemQueryPageSizeOnExit(
    ze_virtual_mem_query_page_size_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemQueryPageSize";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemMapOnEnter(
    ze_virtual_mem_map_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemMap:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " hPhysicalMemory = " + std::to_string((long long unsigned int)*(params->phPhysicalMemory));
    str += " offset = " + std::to_string((long long unsigned int)*(params->poffset));
    str += " access = " + std::to_string((long long unsigned int)*(params->paccess));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemMapOnExit(
    ze_virtual_mem_map_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemMap";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemUnmapOnEnter(
    ze_virtual_mem_unmap_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemUnmap:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemUnmapOnExit(
    ze_virtual_mem_unmap_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemUnmap";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemSetAccessAttributeOnEnter(
    ze_virtual_mem_set_access_attribute_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemSetAccessAttribute:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " access = " + std::to_string((long long unsigned int)*(params->paccess));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemSetAccessAttributeOnExit(
    ze_virtual_mem_set_access_attribute_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemSetAccessAttribute";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

static void zeVirtualMemGetAccessAttributeOnEnter(
    ze_virtual_mem_get_access_attribute_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);


  if (!UniController::IsCollectionEnabled()) {
    ze_instance_data.start_time_host = 0; 
    return;
  }

  if (collector->options_.call_logging) {
    std::string str;
    str += ">>>> [" + std::to_string(UniTimer::GetHostTimestamp()) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str += "zeVirtualMemGetAccessAttribute:";
    str += " hContext = " + std::to_string((long long unsigned int)*(params->phContext));
    str += " ptr = " + std::to_string((long long unsigned int)*(params->pptr));
    str += " size = " + std::to_string((long long unsigned int)*(params->psize));
    str += " access = " + std::to_string((long long unsigned int)*(params->paccess));
    str += " outSize = " + std::to_string((long long unsigned int)*(params->poutSize));
    str += "\n";
  }
  uint64_t start_time_host = 0;
  start_time_host = UniTimer::GetHostTimestamp();
  ze_instance_data.start_time_host = start_time_host;
}

static void zeVirtualMemGetAccessAttributeOnExit(
    ze_virtual_mem_get_access_attribute_params_t* params,
    ze_result_t result,
    void* global_user_data,
    void** instance_user_data) {
  ZeCollector* collector =
    reinterpret_cast<ZeCollector*>(global_user_data);
  uint64_t end_time_host = 0;
  end_time_host = UniTimer::GetHostTimestamp();

  if (!UniController::IsCollectionEnabled()) {
      return;
  }
  uint64_t start_time_host = ze_instance_data.start_time_host;

  if (start_time_host == 0) {
    return;
  }

  uint64_t time;
  time = end_time_host - start_time_host;
  if (collector->options_.call_logging) {
    std::string str;
    str += "<<<< [" + std::to_string(end_time_host) + "] ";
    if (collector->options_.need_pid) {
      str += "<PID:" + std::to_string(utils::GetPid()) + "> ";
    }
    if (collector->options_.need_tid) {
      str += "<TID:" + std::to_string((unsigned int)utils::GetTid()) + "> ";
    }
    str +="zeVirtualMemGetAccessAttribute";
    str += " [" + std::to_string(time) + " ns]";
    if (result == ZE_RESULT_SUCCESS) {
    }
    str += " -> ";
    str +=  GetResultString(result);
    str += "(0x" + std::to_string(result) + ")\n";
  }
}

void EnableTracing(zel_tracer_handle_t tracer) {
  zet_core_callbacks_t prologue = {};
  zet_core_callbacks_t epilogue = {};

  if (options_.kernel_tracing) {
    prologue.Module.pfnCreateCb = zeModuleCreateOnEnter;
    epilogue.Module.pfnCreateCb = zeModuleCreateOnExit;
    prologue.Module.pfnDestroyCb = zeModuleDestroyOnEnter;
    epilogue.Module.pfnDestroyCb = zeModuleDestroyOnExit;
    prologue.Kernel.pfnCreateCb = zeKernelCreateOnEnter;
    epilogue.Kernel.pfnCreateCb = zeKernelCreateOnExit;
    prologue.Kernel.pfnSetGroupSizeCb = zeKernelSetGroupSizeOnEnter;
    epilogue.Kernel.pfnSetGroupSizeCb = zeKernelSetGroupSizeOnExit;
    prologue.Kernel.pfnDestroyCb = zeKernelDestroyOnEnter;
    epilogue.Kernel.pfnDestroyCb = zeKernelDestroyOnExit;
  }

  ze_result_t status = ZE_RESULT_SUCCESS;
  status = zelTracerSetPrologues(tracer, &prologue);
  PTI_ASSERT(status == ZE_RESULT_SUCCESS);
  status = zelTracerSetEpilogues(tracer, &epilogue);
  PTI_ASSERT(status == ZE_RESULT_SUCCESS);
  status = zelTracerSetEnabled(tracer, true);
  PTI_ASSERT(status == ZE_RESULT_SUCCESS);
}

