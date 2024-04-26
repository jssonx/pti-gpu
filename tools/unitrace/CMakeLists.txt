include("../../build_utils/CMakeLists.txt")
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


if (BUILD_WITH_MPI)
  find_package(MPI REQUIRED)
  add_library(unitrace_mpi SHARED
    "${PROJECT_SOURCE_DIR}/src/mpi/mpi.c")

  target_link_libraries(unitrace_mpi
    PUBLIC MPI::MPI_C)
  target_include_directories(unitrace_mpi
    PRIVATE "${PROJECT_SOURCE_DIR}"
    PRIVATE "${I_MPI_ROOT}/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
    PRIVATE "${PROJECT_SOURCE_DIR}/../utils"
    PRIVATE "${PROJECT_SOURCE_DIR}/../../utils"
    PRIVATE "${PROJECT_SOURCE_DIR}/src/mpi"
    PRIVATE "${PROJECT_SOURCE_DIR}/src/levelzero")
  if(CMAKE_INCLUDE_PATH)
    target_include_directories(unitrace_mpi
      PUBLIC "${CMAKE_INCLUDE_PATH}")
  endif()
endif()

add_library(unitrace_tool SHARED
  "${PROJECT_SOURCE_DIR}/src/tracer.cc")
target_compile_options(unitrace_tool PRIVATE -g -O0)
link_directories(${ONEAPI_COMPILER_HOME}/lib)
target_include_directories(unitrace_tool
  PRIVATE "${PROJECT_SOURCE_DIR}"
  PRIVATE "${ONEAPI_COMPILER_HOME}/include"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
  PRIVATE "${PROJECT_SOURCE_DIR}/../utils"
  PRIVATE "${PROJECT_SOURCE_DIR}/../../utils"
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
set(_use_mpi 1)

if (BUILD_WITH_MPI)
  set(_use_mpi 1)
else()
  set(_use_mpi 0)
endif()
target_compile_definitions(unitrace PRIVATE BUILD_WITH_MPI=${_use_mpi})
target_include_directories(unitrace
  PRIVATE "${CMAKE_BINARY_DIR}"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
  PRIVATE "${PROJECT_SOURCE_DIR}/src/levelzero"
  PRIVATE "${PROJECT_SOURCE_DIR}/../utils"
  PRIVATE "${PROJECT_SOURCE_DIR}/../../utils")
if(UNIX)
  target_link_libraries(unitrace pthread dl)
endif()
FindL0Library(unitrace)
FindL0Headers(unitrace)

# Installation

install(TARGETS unitrace unitrace_tool DESTINATION bin)
if (BUILD_WITH_MPI)
  install(TARGETS unitrace_mpi DESTINATION bin)
endif()
