# PC Sampling for Intel GPU

## Introduction

PC Sampling for Intel GPU is a performance analysis tool designed for Intel(R) oneAPI applications. It enables tracing and profiling of hardware utilizations specifically for Intel(R) GPU applications.

## Supported Platforms

- Linux
- Intel(R) oneAPI Base Toolkits
- Intel(R) GPUs including Intel(R) Data Center GPU Max Series

## Requirements

- cmake 3.22 or above (cmake versions prior to 3.22 are not fully tested or validated)
- C++ compiler with C++17 support
- Intel(R) oneAPI Base Toolkits
- Python

## Build

```sh
# set up Intel(R) oneAPI environment
source ~/intel/oneapi/setvars.sh intel64

meson setup build
ninja -C build
```

## Run

```sh
unitrace [options] <application> [args]
```

The options can be one or more of the following:

```
--sampling-interval [-i] <interval> Hardware performance metric sampling interval in us (default is 50 us) in time-based mode
--stall-sampling               Sample hardware execution unit stalls. Valid for Intel(R) Data Center GPU Max Series and later GPUs
```

## Test

### PyTorch
```sh
conda install --file requirements.txt -c intel -c conda-forge
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace ~/pg/ra/pti-gpu/test/python/resnet50.py
```

### Minitest in HPCToolkit
```sh
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace ~/pg/qahpct/minitest/intelgpu/single.sycloffload.ipcx/single.sycloffload.icpx.intelgpu
```

## Stall Sampling

The `--stall-sampling` option works on Intel(R) Data Center GPU Max Series and later products. For kernels with short execution times, the default sampling rate may not be sufficient. In such cases, adjust the sampling rate or interval using the `--sampling-interval [-i]` option.

When using `--stall-sampling`, the tool provides instruction addresses and reasons for stalls, enabling in-depth analysis of execution unit stalls.