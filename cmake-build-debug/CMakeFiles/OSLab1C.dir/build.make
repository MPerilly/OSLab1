# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/msp501/OSLab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/msp501/OSLab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OSLab1C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OSLab1C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OSLab1C.dir/flags.make

CMakeFiles/OSLab1C.dir/main.c.o: CMakeFiles/OSLab1C.dir/flags.make
CMakeFiles/OSLab1C.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/msp501/OSLab1/cmake-build-debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/OSLab1C.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/OSLab1C.dir/main.c.o   -c /home/msp501/OSLab1/main.c

CMakeFiles/OSLab1C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OSLab1C.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/msp501/OSLab1/main.c > CMakeFiles/OSLab1C.dir/main.c.i

CMakeFiles/OSLab1C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OSLab1C.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/msp501/OSLab1/main.c -o CMakeFiles/OSLab1C.dir/main.c.s

CMakeFiles/OSLab1C.dir/main.c.o.requires:
.PHONY : CMakeFiles/OSLab1C.dir/main.c.o.requires

CMakeFiles/OSLab1C.dir/main.c.o.provides: CMakeFiles/OSLab1C.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/OSLab1C.dir/build.make CMakeFiles/OSLab1C.dir/main.c.o.provides.build
.PHONY : CMakeFiles/OSLab1C.dir/main.c.o.provides

CMakeFiles/OSLab1C.dir/main.c.o.provides.build: CMakeFiles/OSLab1C.dir/main.c.o

# Object files for target OSLab1C
OSLab1C_OBJECTS = \
"CMakeFiles/OSLab1C.dir/main.c.o"

# External object files for target OSLab1C
OSLab1C_EXTERNAL_OBJECTS =

OSLab1C: CMakeFiles/OSLab1C.dir/main.c.o
OSLab1C: CMakeFiles/OSLab1C.dir/build.make
OSLab1C: CMakeFiles/OSLab1C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable OSLab1C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OSLab1C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OSLab1C.dir/build: OSLab1C
.PHONY : CMakeFiles/OSLab1C.dir/build

CMakeFiles/OSLab1C.dir/requires: CMakeFiles/OSLab1C.dir/main.c.o.requires
.PHONY : CMakeFiles/OSLab1C.dir/requires

CMakeFiles/OSLab1C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OSLab1C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OSLab1C.dir/clean

CMakeFiles/OSLab1C.dir/depend:
	cd /home/msp501/OSLab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/msp501/OSLab1 /home/msp501/OSLab1 /home/msp501/OSLab1/cmake-build-debug /home/msp501/OSLab1/cmake-build-debug /home/msp501/OSLab1/cmake-build-debug/CMakeFiles/OSLab1C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OSLab1C.dir/depend

