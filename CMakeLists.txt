# version
cmake_minimum_required(VERSION 3.10)
add_definitions(-std=c++17)

# project name
project(x86emu CXX)

# compile config
add_executable(
  x86emu
  memory.cc
  register.cc
  cpu.cc
  instruction.cc
  modrm.cc
  main.cc
  bios.cc
  )

set(EXECUTABLE_OUTPUT_PATH ../)
