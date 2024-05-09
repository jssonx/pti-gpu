project(
  'pcsampling', 
  'cpp',
  version : '0.1',
  meson_version: '>=1.1.0',
  default_options : [
    'buildtype=debugoptimized',
    'cpp_std=gnu++17'
  ],
)

# Find support for Intel performance monitoring via Level Zero.
level0_dep = dependency('level-zero', required: false)
if not level0_dep.found()
  error('Level Zero library not found. Please check installation.')
endif

inc_dirs = include_directories('src', 'src/levelzero')

unitrace_tool = shared_library(
  'unitrace_tool',
  sources : ['src/tracer.cc'],
  include_directories : inc_dirs,
  dependencies : [level0_dep],
  cpp_args : ['-fvisibility=default'],
  link_args : ['-L/usr/lib/x86_64-linux-gnu/', '-liga64'],
)

unitrace_exe = executable(
  'unitrace',
  sources : ['src/unitrace.cc'],
  include_directories : inc_dirs,
  link_with : [unitrace_tool],
  dependencies : [level0_dep],
  link_args : ['-pthread', '-ldl'],
)