rm -rf build
meson setup build
ninja -C build
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace /home/users/yuning/pg/qahpct/minitest/intelgpu/single.sycloffload.ipcx/single.sycloffload.icpx.intelgpu
unitrace --stall-sampling -o ~/pg/ra/pti-gpu/unitrace /home/users/yuning/pg/ra/pti-gpu/python/resnet50.py