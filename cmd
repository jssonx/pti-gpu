rm -rf build
meson setup build
ninja -C build
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace ~/pg/qahpct/minitest/intelgpu/single.sycloffload.ipcx/single.sycloffload.icpx.intelgpu
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace ~/pg/ra/pti-gpu/test/python/resnet50.py