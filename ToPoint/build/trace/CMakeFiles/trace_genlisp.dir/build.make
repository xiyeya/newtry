# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/xuan/projects/ToPoint/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xuan/projects/ToPoint/build

# Utility rule file for trace_genlisp.

# Include the progress variables for this target.
include trace/CMakeFiles/trace_genlisp.dir/progress.make

trace_genlisp: trace/CMakeFiles/trace_genlisp.dir/build.make

.PHONY : trace_genlisp

# Rule to build all files generated by this target.
trace/CMakeFiles/trace_genlisp.dir/build: trace_genlisp

.PHONY : trace/CMakeFiles/trace_genlisp.dir/build

trace/CMakeFiles/trace_genlisp.dir/clean:
	cd /home/xuan/projects/ToPoint/build/trace && $(CMAKE_COMMAND) -P CMakeFiles/trace_genlisp.dir/cmake_clean.cmake
.PHONY : trace/CMakeFiles/trace_genlisp.dir/clean

trace/CMakeFiles/trace_genlisp.dir/depend:
	cd /home/xuan/projects/ToPoint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuan/projects/ToPoint/src /home/xuan/projects/ToPoint/src/trace /home/xuan/projects/ToPoint/build /home/xuan/projects/ToPoint/build/trace /home/xuan/projects/ToPoint/build/trace/CMakeFiles/trace_genlisp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : trace/CMakeFiles/trace_genlisp.dir/depend
