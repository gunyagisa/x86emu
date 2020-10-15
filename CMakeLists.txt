# version
cmake_minimum_required(VERSION 3.10)
add_definitions(-std=c++17)

# project name
project(x86emu CXX)

# compile config
set(CMAKE_CXX_COMPILER clang++)
add_executable(
  x86emu
  memory.cc
  register.cc
  cpu.cc
  instruction.cc
  modrm.cc
  main.cc
  util.cc
  bios.cc
  )

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
target_link_libraries(x86emu glut GL pthread)

set(EXECUTABLE_OUTPUT_PATH ../)
