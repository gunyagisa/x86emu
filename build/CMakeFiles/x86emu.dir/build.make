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
CMAKE_SOURCE_DIR = /home/gunyagisa/programs/cpp/x86emu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gunyagisa/programs/cpp/x86emu/build

# Include any dependencies generated for this target.
include CMakeFiles/x86emu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/x86emu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/x86emu.dir/flags.make

CMakeFiles/x86emu.dir/memory.cc.o: CMakeFiles/x86emu.dir/flags.make
CMakeFiles/x86emu.dir/memory.cc.o: ../memory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/x86emu.dir/memory.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x86emu.dir/memory.cc.o -c /home/gunyagisa/programs/cpp/x86emu/memory.cc

CMakeFiles/x86emu.dir/memory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86emu.dir/memory.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/memory.cc > CMakeFiles/x86emu.dir/memory.cc.i

CMakeFiles/x86emu.dir/memory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86emu.dir/memory.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/memory.cc -o CMakeFiles/x86emu.dir/memory.cc.s

CMakeFiles/x86emu.dir/memory.cc.o.requires:

.PHONY : CMakeFiles/x86emu.dir/memory.cc.o.requires

CMakeFiles/x86emu.dir/memory.cc.o.provides: CMakeFiles/x86emu.dir/memory.cc.o.requires
	$(MAKE) -f CMakeFiles/x86emu.dir/build.make CMakeFiles/x86emu.dir/memory.cc.o.provides.build
.PHONY : CMakeFiles/x86emu.dir/memory.cc.o.provides

CMakeFiles/x86emu.dir/memory.cc.o.provides.build: CMakeFiles/x86emu.dir/memory.cc.o


CMakeFiles/x86emu.dir/register.cc.o: CMakeFiles/x86emu.dir/flags.make
CMakeFiles/x86emu.dir/register.cc.o: ../register.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/x86emu.dir/register.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x86emu.dir/register.cc.o -c /home/gunyagisa/programs/cpp/x86emu/register.cc

CMakeFiles/x86emu.dir/register.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86emu.dir/register.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/register.cc > CMakeFiles/x86emu.dir/register.cc.i

CMakeFiles/x86emu.dir/register.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86emu.dir/register.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/register.cc -o CMakeFiles/x86emu.dir/register.cc.s

CMakeFiles/x86emu.dir/register.cc.o.requires:

.PHONY : CMakeFiles/x86emu.dir/register.cc.o.requires

CMakeFiles/x86emu.dir/register.cc.o.provides: CMakeFiles/x86emu.dir/register.cc.o.requires
	$(MAKE) -f CMakeFiles/x86emu.dir/build.make CMakeFiles/x86emu.dir/register.cc.o.provides.build
.PHONY : CMakeFiles/x86emu.dir/register.cc.o.provides

CMakeFiles/x86emu.dir/register.cc.o.provides.build: CMakeFiles/x86emu.dir/register.cc.o


CMakeFiles/x86emu.dir/cpu.cc.o: CMakeFiles/x86emu.dir/flags.make
CMakeFiles/x86emu.dir/cpu.cc.o: ../cpu.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/x86emu.dir/cpu.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x86emu.dir/cpu.cc.o -c /home/gunyagisa/programs/cpp/x86emu/cpu.cc

CMakeFiles/x86emu.dir/cpu.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86emu.dir/cpu.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/cpu.cc > CMakeFiles/x86emu.dir/cpu.cc.i

CMakeFiles/x86emu.dir/cpu.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86emu.dir/cpu.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/cpu.cc -o CMakeFiles/x86emu.dir/cpu.cc.s

CMakeFiles/x86emu.dir/cpu.cc.o.requires:

.PHONY : CMakeFiles/x86emu.dir/cpu.cc.o.requires

CMakeFiles/x86emu.dir/cpu.cc.o.provides: CMakeFiles/x86emu.dir/cpu.cc.o.requires
	$(MAKE) -f CMakeFiles/x86emu.dir/build.make CMakeFiles/x86emu.dir/cpu.cc.o.provides.build
.PHONY : CMakeFiles/x86emu.dir/cpu.cc.o.provides

CMakeFiles/x86emu.dir/cpu.cc.o.provides.build: CMakeFiles/x86emu.dir/cpu.cc.o


CMakeFiles/x86emu.dir/instruction.cc.o: CMakeFiles/x86emu.dir/flags.make
CMakeFiles/x86emu.dir/instruction.cc.o: ../instruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/x86emu.dir/instruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x86emu.dir/instruction.cc.o -c /home/gunyagisa/programs/cpp/x86emu/instruction.cc

CMakeFiles/x86emu.dir/instruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86emu.dir/instruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/instruction.cc > CMakeFiles/x86emu.dir/instruction.cc.i

CMakeFiles/x86emu.dir/instruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86emu.dir/instruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/instruction.cc -o CMakeFiles/x86emu.dir/instruction.cc.s

CMakeFiles/x86emu.dir/instruction.cc.o.requires:

.PHONY : CMakeFiles/x86emu.dir/instruction.cc.o.requires

CMakeFiles/x86emu.dir/instruction.cc.o.provides: CMakeFiles/x86emu.dir/instruction.cc.o.requires
	$(MAKE) -f CMakeFiles/x86emu.dir/build.make CMakeFiles/x86emu.dir/instruction.cc.o.provides.build
.PHONY : CMakeFiles/x86emu.dir/instruction.cc.o.provides

CMakeFiles/x86emu.dir/instruction.cc.o.provides.build: CMakeFiles/x86emu.dir/instruction.cc.o


CMakeFiles/x86emu.dir/main.cc.o: CMakeFiles/x86emu.dir/flags.make
CMakeFiles/x86emu.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/x86emu.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x86emu.dir/main.cc.o -c /home/gunyagisa/programs/cpp/x86emu/main.cc

CMakeFiles/x86emu.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86emu.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunyagisa/programs/cpp/x86emu/main.cc > CMakeFiles/x86emu.dir/main.cc.i

CMakeFiles/x86emu.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86emu.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunyagisa/programs/cpp/x86emu/main.cc -o CMakeFiles/x86emu.dir/main.cc.s

CMakeFiles/x86emu.dir/main.cc.o.requires:

.PHONY : CMakeFiles/x86emu.dir/main.cc.o.requires

CMakeFiles/x86emu.dir/main.cc.o.provides: CMakeFiles/x86emu.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/x86emu.dir/build.make CMakeFiles/x86emu.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/x86emu.dir/main.cc.o.provides

CMakeFiles/x86emu.dir/main.cc.o.provides.build: CMakeFiles/x86emu.dir/main.cc.o


# Object files for target x86emu
x86emu_OBJECTS = \
"CMakeFiles/x86emu.dir/memory.cc.o" \
"CMakeFiles/x86emu.dir/register.cc.o" \
"CMakeFiles/x86emu.dir/cpu.cc.o" \
"CMakeFiles/x86emu.dir/instruction.cc.o" \
"CMakeFiles/x86emu.dir/main.cc.o"

# External object files for target x86emu
x86emu_EXTERNAL_OBJECTS =

../x86emu: CMakeFiles/x86emu.dir/memory.cc.o
../x86emu: CMakeFiles/x86emu.dir/register.cc.o
../x86emu: CMakeFiles/x86emu.dir/cpu.cc.o
../x86emu: CMakeFiles/x86emu.dir/instruction.cc.o
../x86emu: CMakeFiles/x86emu.dir/main.cc.o
../x86emu: CMakeFiles/x86emu.dir/build.make
../x86emu: CMakeFiles/x86emu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../x86emu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/x86emu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/x86emu.dir/build: ../x86emu

.PHONY : CMakeFiles/x86emu.dir/build

CMakeFiles/x86emu.dir/requires: CMakeFiles/x86emu.dir/memory.cc.o.requires
CMakeFiles/x86emu.dir/requires: CMakeFiles/x86emu.dir/register.cc.o.requires
CMakeFiles/x86emu.dir/requires: CMakeFiles/x86emu.dir/cpu.cc.o.requires
CMakeFiles/x86emu.dir/requires: CMakeFiles/x86emu.dir/instruction.cc.o.requires
CMakeFiles/x86emu.dir/requires: CMakeFiles/x86emu.dir/main.cc.o.requires

.PHONY : CMakeFiles/x86emu.dir/requires

CMakeFiles/x86emu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/x86emu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/x86emu.dir/clean

CMakeFiles/x86emu.dir/depend:
	cd /home/gunyagisa/programs/cpp/x86emu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gunyagisa/programs/cpp/x86emu /home/gunyagisa/programs/cpp/x86emu /home/gunyagisa/programs/cpp/x86emu/build /home/gunyagisa/programs/cpp/x86emu/build /home/gunyagisa/programs/cpp/x86emu/build/CMakeFiles/x86emu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/x86emu.dir/depend

