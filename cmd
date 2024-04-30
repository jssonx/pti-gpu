rm -rf build
meson setup build
ninja -C build
unitrace ~/pg/qahpct/minitest/intelgpu/single.sycloffload.ipcx/single.sycloffload.icpx.intelgpu
unitrace ~/pg/ra/pti-gpu/test/python/resnet50.py