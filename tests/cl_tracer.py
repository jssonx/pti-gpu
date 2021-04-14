import os
import subprocess
import sys

import cl_gemm
import dpc_gemm
import utils

def config(path):
  p = subprocess.Popen(["cmake",\
    "-DCMAKE_BUILD_TYPE=" + utils.get_build_flag(), ".."],\
    cwd = path, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  p.wait()
  stdout, stderr = utils.run_process(p)
  if stderr and stderr.find("CMake Error") != -1:
    return stderr
  return None

def build(path):
  p = subprocess.Popen(["make"], cwd = path,\
    stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  p.wait()
  stdout, stderr = utils.run_process(p)
  if stderr and stderr.lower().find("error") != -1:
    return stderr
  return None

def run(path, option):
  if option == "dpc":
    app_folder = utils.get_sample_build_path("dpc_gemm")
    app_file = os.path.join(app_folder, "dpc_gemm")
    p = subprocess.Popen(["./cl_tracer", "-h", "-d", app_file, "cpu", "1024", "1"],\
      cwd = path, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  else:
    app_folder = utils.get_sample_build_path("cl_gemm")
    app_file = os.path.join(app_folder, "cl_gemm")
    if option == "gpu":
      p = subprocess.Popen(["./cl_tracer", "-h", "-d", app_file, "gpu", "1024", "1"],\
        cwd = path, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    else:
      p = subprocess.Popen(["./cl_tracer", option, app_file, "cpu", "1024", "1"],\
        cwd = path, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  stdout, stderr = utils.run_process(p)
  if not stderr:
    return stdout
  if stdout.find(" CORRECT") == -1:
    return stdout
  if stderr.find("WARNING") != -1:
    return stderr
  return None

def main(option):
  path = utils.get_tool_build_path("cl_tracer")
  if option == "dpc":
    log = dpc_gemm.main("cpu")
  elif option == "gpu":
    log = cl_gemm.main("gpu")
  else:
    log = cl_gemm.main("cpu")
  if log:
    return log
  log = config(path)
  if log:
    return log
  log = build(path)
  if log:
    return log
  log = run(path, option)
  if log:
    return log

if __name__ == "__main__":
  option = "-c"
  if len(sys.argv) > 1 and sys.argv[1] == "-h":
    option = "-h"
  if len(sys.argv) > 1 and sys.argv[1] == "-d":
    option = "-d"
  if len(sys.argv) > 1 and sys.argv[1] == "-t":
    option = "-t"
  if len(sys.argv) > 1 and sys.argv[1] == "--chrome-call-logging":
    option = "--chrome-call-logging"
  if len(sys.argv) > 1 and sys.argv[1] == "--chrome-device-timeline":
    option = "--chrome-device-timeline"
  if len(sys.argv) > 1 and sys.argv[1] == "--chrome-device-stages":
    option = "--chrome-device-stages"
  if len(sys.argv) > 1 and sys.argv[1] == "gpu":
    option = "gpu"
  if len(sys.argv) > 1 and sys.argv[1] == "dpc":
    option = "dpc"
  log = main(option)
  if log:
    print(log)