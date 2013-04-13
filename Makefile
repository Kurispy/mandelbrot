# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/Desktop/ecs175/mandelbrot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/Desktop/ecs175/mandelbrot

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chris/Desktop/ecs175/mandelbrot/CMakeFiles /home/chris/Desktop/ecs175/mandelbrot/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chris/Desktop/ecs175/mandelbrot/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named demo4.x

# Build rule for target.
demo4.x: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 demo4.x
.PHONY : demo4.x

# fast build rule for target.
demo4.x/fast:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/build
.PHONY : demo4.x/fast

glutwidget.o: glutwidget.cpp.o
.PHONY : glutwidget.o

# target to build an object file
glutwidget.cpp.o:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/glutwidget.cpp.o
.PHONY : glutwidget.cpp.o

glutwidget.i: glutwidget.cpp.i
.PHONY : glutwidget.i

# target to preprocess a source file
glutwidget.cpp.i:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/glutwidget.cpp.i
.PHONY : glutwidget.cpp.i

glutwidget.s: glutwidget.cpp.s
.PHONY : glutwidget.s

# target to generate assembly for a file
glutwidget.cpp.s:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/glutwidget.cpp.s
.PHONY : glutwidget.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/main.cpp.s
.PHONY : main.cpp.s

shader_utils.o: shader_utils.cpp.o
.PHONY : shader_utils.o

# target to build an object file
shader_utils.cpp.o:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/shader_utils.cpp.o
.PHONY : shader_utils.cpp.o

shader_utils.i: shader_utils.cpp.i
.PHONY : shader_utils.i

# target to preprocess a source file
shader_utils.cpp.i:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/shader_utils.cpp.i
.PHONY : shader_utils.cpp.i

shader_utils.s: shader_utils.cpp.s
.PHONY : shader_utils.s

# target to generate assembly for a file
shader_utils.cpp.s:
	$(MAKE) -f CMakeFiles/demo4.x.dir/build.make CMakeFiles/demo4.x.dir/shader_utils.cpp.s
.PHONY : shader_utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... demo4.x"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... glutwidget.o"
	@echo "... glutwidget.i"
	@echo "... glutwidget.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... shader_utils.o"
	@echo "... shader_utils.i"
	@echo "... shader_utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

