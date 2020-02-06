# version
cmake_minimum_required(VERSION 2.8)
# project configure
project(x86emu CXX)

# sub directory
add_subdirectory(src)

add_executable(a.out main.cc memory.cc register.cc cpu.cc)
