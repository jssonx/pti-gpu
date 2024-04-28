# Build Utils
set(PTI_CMAKE_MACRO_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE INTERNAL "")

macro(SetRequiredCMakeVersion)
  set(REQUIRED_CMAKE_VERSION 3.12)
endmacro()

macro(RequirePythonInterp)
  if(NOT DEFINED _Python_EXECUTABLE)
    find_package(Python COMPONENTS Interpreter REQUIRED)
    set(PYTHON_EXECUTABLE "${Python_EXECUTABLE}")
  else()
    set(PYTHON_EXECUTABLE "${_Python_EXECUTABLE}")
  endif()
endmacro()

macro(SetCompilerFlags)
  if(WIN32)
    add_definitions(-DNOMINMAX)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /Od")
    else()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG")
    endif()
  else()
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fvisibility=default")
    else()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fvisibility=hidden -DNDEBUG")
    endif()
  endif()
endmacro()

macro(SetBuildType)
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
  endif()
  message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "Bitness: 64 bits")
  else()
    message(FATAL_ERROR "32-bit mode is not supported")
  endif()
endmacro()

macro(GetLevelZeroHeaders TARGET)
  set(L0_INC_PATH "${CMAKE_BINARY_DIR}")
  RequirePythonInterp()

  add_custom_target(level_zero_headers ALL
                    DEPENDS ${L0_INC_PATH}/level_zero/ze_api.h
                            ${L0_INC_PATH}/level_zero/zes_api.h
                            ${L0_INC_PATH}/level_zero/zet_api.h
                            ${L0_INC_PATH}/level_zero/layers/zel_tracing_api.h)
  add_custom_command(OUTPUT ${L0_INC_PATH}/level_zero/ze_api.h
                            ${L0_INC_PATH}/level_zero/zes_api.h
                            ${L0_INC_PATH}/level_zero/zet_api.h
                            ${L0_INC_PATH}/level_zero/layers/zel_tracing_api.h
                    COMMAND "${PYTHON_EXECUTABLE}" "${PTI_CMAKE_MACRO_DIR}/get_ze_headers.py" ${L0_INC_PATH} ${CMAKE_BINARY_DIR})
  target_include_directories(${TARGET}
    PUBLIC "${L0_INC_PATH}")
  add_dependencies(${TARGET}
    level_zero_headers)
endmacro()

macro(FindL0Library TARGET)
  if(WIN32)
    find_library(L0_LIB_PATH
      NAMES ze_loader
      PATHS ${CMAKE_LIBRARY_PATH})
    if(NOT L0_LIB_PATH)
      foreach(VALUE IN ITEMS $ENV{PATH})
        if(VALUE MATCHES "[S|s]ystem32*$")
          set(WIN_SYS_PATH ${VALUE})
          break()
        endif()
      endforeach()
      file(GLOB_RECURSE L0_DLL_PATH "${WIN_SYS_PATH}/ze_loader.dll")
      if(NOT L0_DLL_PATH)
        message(FATAL_ERROR
          "Level Zero loader is not found. "
          "You may need to install oneAPI Level Zero loader to fix this issue.")
      else()
        message(STATUS
          "Level Zero Loader is found at ${L0_DLL_PATH}")
        find_library(L0_LIB_PATH
          NAMES ze_loader
          PATHS ${SEARCH_LIB_PATH})
        if(NOT L0_LIB_PATH)
          RequirePythonInterp()

          add_custom_target(level_zero_lib ALL
                            DEPENDS ${CMAKE_BINARY_DIR}/ze_loader.lib)
          add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/ze_loader.lib
                             COMMAND "${PYTHON_EXECUTABLE}" "${PTI_CMAKE_MACRO_DIR}/convert_dll_to_lib.py" ${CMAKE_BINARY_DIR} ${L0_DLL_PATH})
          add_dependencies(${TARGET} level_zero_lib)
          target_link_libraries(${TARGET} "${CMAKE_BINARY_DIR}/ze_loader.lib")
        else()
          message(STATUS
            "Level Zero library is found at ${L0_LIB_PATH}")
          target_link_libraries(${TARGET}
            "${L0_LIB_PATH}")
        endif()
      endif()
    else()
      message(STATUS
        "Level Zero loader is found at ${L0_LIB_PATH}")
      target_link_libraries(${TARGET}
        "${L0_LIB_PATH}")
    endif()
  else()
    if(DEFINED ENV{LD_LIBRARY_PATH})
      string(COMPARE EQUAL "$ENV{LD_LIBRARY_PATH}" "" RESULT)
      if (NOT RESULT)
        string(REPLACE ":" ";" SEARCH_LIB_PATH $ENV{LD_LIBRARY_PATH})
      endif()
    endif()

    find_library(L0_LIB_PATH
      NAMES ze_loader
      PATHS ${SEARCH_LIB_PATH})
    if(NOT L0_LIB_PATH)
      message(FATAL_ERROR
        "Level Zero loader is not found. "
        "You may need to install oneAPI Level Zero loader to fix this issue.")
    else()
      message(STATUS
        "Level Zero loader is found at ${L0_LIB_PATH}")
    endif()

    target_link_libraries(${TARGET}
      "${L0_LIB_PATH}")
  endif()
endmacro()

macro(FindL0Headers TARGET)
  if(CMAKE_INCLUDE_PATH)
    set(CMAKE_REQUIRED_INCLUDES ${CMAKE_INCLUDE_PATH})
  endif()
  include(CheckIncludeFileCXX)
  check_include_file_cxx(level_zero/ze_api.h LO_CORE_INC_FOUND)
  check_include_file_cxx(level_zero/zet_api.h LO_TOOLS_INC_FOUND)
  check_include_file_cxx(level_zero/zes_api.h LO_SYSMAN_INC_FOUND)
  check_include_file_cxx(level_zero/layers/zel_tracing_api.h LO_LAYERS_INC_FOUND)
  if ((NOT LO_CORE_INC_FOUND) OR (NOT LO_TOOLS_INC_FOUND) OR (NOT LO_LAYERS_INC_FOUND) OR (NOT LO_SYSMAN_INC_FOUND))
    message(STATUS "Level Zero headers are not found, will be downloaded automatically")
    GetLevelZeroHeaders(${TARGET})
  endif()
  set(CMAKE_REQUIRED_INCLUDES)
endmacro()

macro(FindL0HeadersPath TARGET L0_GEN_SCRIPT)
  RequirePythonInterp()
  find_path(L0_INC_PATH
    NAMES level_zero
    PATHS ENV CPATH)
  if (NOT L0_INC_PATH)
    message(FATAL_ERROR
      "Level Zero headers path is not found.\n"
      "You may need to install oneAPI Level Zero Driver to fix this issue.")
  else()
    message(STATUS "Level Zero headers are found at ${L0_INC_PATH}")
  endif()

  set(L0_GEN_INC_PATH "${CMAKE_BINARY_DIR}")
  add_custom_target(ze_gen_headers ALL
                    DEPENDS ${L0_GEN_INC_PATH}/tracing.gen)
  add_custom_command(OUTPUT ${L0_GEN_INC_PATH}/tracing.gen
                     COMMAND "${PYTHON_EXECUTABLE}" ${L0_GEN_SCRIPT} ${L0_GEN_INC_PATH} "${L0_INC_PATH}/level_zero")
  target_include_directories(${TARGET}
    PUBLIC "${L0_GEN_INC_PATH}")
  add_dependencies(${TARGET}
    ze_gen_headers)
endmacro()


# Setup
SetRequiredCMakeVersion()
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION})

project(PTI_Tools_UniTrace C CXX)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SetCompilerFlags()
SetBuildType()

option(BUILD_WITH_MPI
  "Build with support for MPI tracing"
  ON
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -O0 -fvisibility=default")

# Tool Library
macro(FindHeadersPath TARGET L0_GEN_SCRIPT GEN_FILE_NAME custom_target)
  RequirePythonInterp()
  find_path(L0_INC_PATH
    NAMES level_zero
    PATHS ENV CPATH)
  if (NOT L0_INC_PATH)
    message(FATAL_ERROR
      "Level Zero headers path is not found.\n"
      "You may need to install oneAPI Level Zero Driver to fix this issue.")
  else()
    message(STATUS "Level Zero headers are found at ${L0_INC_PATH}")
  endif()

  set(L0_GEN_INC_PATH "${CMAKE_BINARY_DIR}")
  add_custom_target(${custom_target} ALL
                    DEPENDS ${L0_GEN_INC_PATH}/${GEN_FILE_NAME})
  add_custom_command(OUTPUT ${L0_GEN_INC_PATH}/${GEN_FILE_NAME}
                     COMMAND "${PYTHON_EXECUTABLE}" ${L0_GEN_SCRIPT} ${L0_GEN_INC_PATH} "${L0_INC_PATH}/level_zero")
  target_include_directories(${TARGET}
    PUBLIC "${L0_GEN_INC_PATH}")
  add_dependencies(${TARGET}
    ${custom_target})
endmacro()

add_library(unitrace_tool SHARED
  "${PROJECT_SOURCE_DIR}/src/tracer.cc")
link_directories(${ONEAPI_COMPILER_HOME}/lib)
target_include_directories(unitrace_tool
  PRIVATE "${PROJECT_SOURCE_DIR}"
  PRIVATE "${ONEAPI_COMPILER_HOME}/include"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
  PRIVATE "${PROJECT_SOURCE_DIR}/utils"
  PRIVATE "${PROJECT_SOURCE_DIR}/src/levelzero")
target_compile_definitions(unitrace_tool PUBLIC PTI_LEVEL_ZERO=1)
if(CMAKE_INCLUDE_PATH)
  target_include_directories(unitrace_tool
    PUBLIC "${CMAKE_INCLUDE_PATH}")
endif()

FindL0Library(unitrace_tool)
FindL0Headers(unitrace_tool)

target_include_directories(unitrace_tool PRIVATE "${L0_INC_PATH}")

# Loader

add_executable(unitrace "${PROJECT_SOURCE_DIR}/src/unitrace.cc")
target_include_directories(unitrace
  PRIVATE "${CMAKE_BINARY_DIR}"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
  PRIVATE "${PROJECT_SOURCE_DIR}/src/levelzero"
  PRIVATE "${PROJECT_SOURCE_DIR}/utils")
if(UNIX)
  target_link_libraries(unitrace pthread dl)
endif()
FindL0Library(unitrace)
FindL0Headers(unitrace)

# Installation

install(TARGETS unitrace unitrace_tool DESTINATION bin)