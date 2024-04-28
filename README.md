# PC Sampling in Intel GPU

## Introduction

This a performnce tool for Intel(R) oneAPI applications. It traces and profiles host/device activites, interactions and hardware utilizations for Intel(R) GPU applications.

## Supported Platforms

- Linux
- Intel(R) oneAPI Base Toolkits
- Intel(R) GPUs including Intel(R) Data Center GPU Max Series

## Requirements

- cmake 3.22 or above (cmake versions prior to 3.22 are not fully tested or validated)
- C++ compiler with C++17 support
- Intel(R) oneAPI Base Toolkits
- Python
- Intel(R) MPI (optional)

## Build

```sh
set up Intel(R) oneAPI environment

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

### Stall Sampling

The **--stall-sampling** works on Intel(R) Data Center GPU Max Series and later products.

![Metric Query!](/tools/unitrace/doc/images/stall-sampling.png)

To kernels that take short time, you may find that the default sampling rate is not high enough and the sampling rate or the sampling interval needs to be changed using **--sampling-interval [-i]** option.

In case of execution unit stall analysis, the **--stall-sampling** will give you instruction addresses and reasons of stalls.