# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gunyagisa/programs/cpp/x86emu/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gunyagisa/programs/cpp/x86emu/src/build

# Include any dependencies generated for this target.
include CMakeFiles/a.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.dir/flags.make

CMakeFiles/a.out.dir/memory.cc.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/memory.cc.o: ../memory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.dir/memory.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/memory.cc.o -c /home/gunyagisa/programs/cpp/x86emu/src/memory.cc

CMakeFiles/a.out.dir/memory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/memory.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/src/memory.cc > CMakeFiles/a.out.dir/memory.cc.i

CMakeFiles/a.out.dir/memory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/memory.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/src/memory.cc -o CMakeFiles/a.out.dir/memory.cc.s

CMakeFiles/a.out.dir/memory.cc.o.requires:

.PHONY : CMakeFiles/a.out.dir/memory.cc.o.requires

CMakeFiles/a.out.dir/memory.cc.o.provides: CMakeFiles/a.out.dir/memory.cc.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/memory.cc.o.provides.build
.PHONY : CMakeFiles/a.out.dir/memory.cc.o.provides

CMakeFiles/a.out.dir/memory.cc.o.provides.build: CMakeFiles/a.out.dir/memory.cc.o


CMakeFiles/a.out.dir/register.cc.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/register.cc.o: ../register.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.dir/register.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/register.cc.o -c /home/gunyagisa/programs/cpp/x86emu/src/register.cc

CMakeFiles/a.out.dir/register.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/register.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/src/register.cc > CMakeFiles/a.out.dir/register.cc.i

CMakeFiles/a.out.dir/register.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/register.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/src/register.cc -o CMakeFiles/a.out.dir/register.cc.s

CMakeFiles/a.out.dir/register.cc.o.requires:

.PHONY : CMakeFiles/a.out.dir/register.cc.o.requires

CMakeFiles/a.out.dir/register.cc.o.provides: CMakeFiles/a.out.dir/register.cc.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/register.cc.o.provides.build
.PHONY : CMakeFiles/a.out.dir/register.cc.o.provides

CMakeFiles/a.out.dir/register.cc.o.provides.build: CMakeFiles/a.out.dir/register.cc.o


CMakeFiles/a.out.dir/cpu.cc.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/cpu.cc.o: ../cpu.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.dir/cpu.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/cpu.cc.o -c /home/gunyagisa/programs/cpp/x86emu/src/cpu.cc

CMakeFiles/a.out.dir/cpu.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/cpu.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/src/cpu.cc > CMakeFiles/a.out.dir/cpu.cc.i

CMakeFiles/a.out.dir/cpu.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/cpu.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/src/cpu.cc -o CMakeFiles/a.out.dir/cpu.cc.s

CMakeFiles/a.out.dir/cpu.cc.o.requires:

.PHONY : CMakeFiles/a.out.dir/cpu.cc.o.requires

CMakeFiles/a.out.dir/cpu.cc.o.provides: CMakeFiles/a.out.dir/cpu.cc.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/cpu.cc.o.provides.build
.PHONY : CMakeFiles/a.out.dir/cpu.cc.o.provides

CMakeFiles/a.out.dir/cpu.cc.o.provides.build: CMakeFiles/a.out.dir/cpu.cc.o


# Object files for target a.out
a_out_OBJECTS = \
"CMakeFiles/a.out.dir/memory.cc.o" \
"CMakeFiles/a.out.dir/register.cc.o" \
"CMakeFiles/a.out.dir/cpu.cc.o"

# External object files for target a.out
a_out_EXTERNAL_OBJECTS =

a.out: CMakeFiles/a.out.dir/memory.cc.o
a.out: CMakeFiles/a.out.dir/register.cc.o
a.out: CMakeFiles/a.out.dir/cpu.cc.o
a.out: CMakeFiles/a.out.dir/build.make
a.out: CMakeFiles/a.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gunyagisa/programs/cpp/x86emu/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable a.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.dir/build: a.out

.PHONY : CMakeFiles/a.out.dir/build

CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/memory.cc.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/register.cc.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/cpu.cc.o.requires

.PHONY : CMakeFiles/a.out.dir/requires

CMakeFiles/a.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.dir/clean

CMakeFiles/a.out.dir/depend:
	cd /home/gunyagisa/programs/cpp/x86emu/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gunyagisa/programs/cpp/x86emu/src /home/gunyagisa/programs/cpp/x86emu/src /home/gunyagisa/programs/cpp/x86emu/src/build /home/gunyagisa/programs/cpp/x86emu/src/build /home/gunyagisa/programs/cpp/x86emu/src/build/CMakeFiles/a.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.dir/depend

