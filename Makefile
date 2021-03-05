# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/bp1/sandbox/neato-xv11-lidar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bp1/sandbox/neato-xv11-lidar

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/bp1/sandbox/neato-xv11-lidar/CMakeFiles /home/bp1/sandbox/neato-xv11-lidar/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/bp1/sandbox/neato-xv11-lidar/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named printRPM

# Build rule for target.
printRPM: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 printRPM
.PHONY : printRPM

# fast build rule for target.
printRPM/fast:
	$(MAKE) -f CMakeFiles/printRPM.dir/build.make CMakeFiles/printRPM.dir/build
.PHONY : printRPM/fast

#=============================================================================
# Target rules for targets named printdata

# Build rule for target.
printdata: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 printdata
.PHONY : printdata

# fast build rule for target.
printdata/fast:
	$(MAKE) -f CMakeFiles/printdata.dir/build.make CMakeFiles/printdata.dir/build
.PHONY : printdata/fast

#=============================================================================
# Target rules for targets named pwm

# Build rule for target.
pwm: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 pwm
.PHONY : pwm

# fast build rule for target.
pwm/fast:
	$(MAKE) -f CMakeFiles/pwm.dir/build.make CMakeFiles/pwm.dir/build
.PHONY : pwm/fast

#=============================================================================
# Target rules for targets named xv11_static

# Build rule for target.
xv11_static: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 xv11_static
.PHONY : xv11_static

# fast build rule for target.
xv11_static/fast:
	$(MAKE) -f CMakeFiles/xv11_static.dir/build.make CMakeFiles/xv11_static.dir/build
.PHONY : xv11_static/fast

#=============================================================================
# Target rules for targets named xv11

# Build rule for target.
xv11: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 xv11
.PHONY : xv11

# fast build rule for target.
xv11/fast:
	$(MAKE) -f CMakeFiles/xv11.dir/build.make CMakeFiles/xv11.dir/build
.PHONY : xv11/fast

printRPM.o: printRPM.cpp.o

.PHONY : printRPM.o

# target to build an object file
printRPM.cpp.o:
	$(MAKE) -f CMakeFiles/printRPM.dir/build.make CMakeFiles/printRPM.dir/printRPM.cpp.o
.PHONY : printRPM.cpp.o

printRPM.i: printRPM.cpp.i

.PHONY : printRPM.i

# target to preprocess a source file
printRPM.cpp.i:
	$(MAKE) -f CMakeFiles/printRPM.dir/build.make CMakeFiles/printRPM.dir/printRPM.cpp.i
.PHONY : printRPM.cpp.i

printRPM.s: printRPM.cpp.s

.PHONY : printRPM.s

# target to generate assembly for a file
printRPM.cpp.s:
	$(MAKE) -f CMakeFiles/printRPM.dir/build.make CMakeFiles/printRPM.dir/printRPM.cpp.s
.PHONY : printRPM.cpp.s

printdata.o: printdata.cpp.o

.PHONY : printdata.o

# target to build an object file
printdata.cpp.o:
	$(MAKE) -f CMakeFiles/printdata.dir/build.make CMakeFiles/printdata.dir/printdata.cpp.o
.PHONY : printdata.cpp.o

printdata.i: printdata.cpp.i

.PHONY : printdata.i

# target to preprocess a source file
printdata.cpp.i:
	$(MAKE) -f CMakeFiles/printdata.dir/build.make CMakeFiles/printdata.dir/printdata.cpp.i
.PHONY : printdata.cpp.i

printdata.s: printdata.cpp.s

.PHONY : printdata.s

# target to generate assembly for a file
printdata.cpp.s:
	$(MAKE) -f CMakeFiles/printdata.dir/build.make CMakeFiles/printdata.dir/printdata.cpp.s
.PHONY : printdata.cpp.s

pwm.o: pwm.cpp.o

.PHONY : pwm.o

# target to build an object file
pwm.cpp.o:
	$(MAKE) -f CMakeFiles/pwm.dir/build.make CMakeFiles/pwm.dir/pwm.cpp.o
.PHONY : pwm.cpp.o

pwm.i: pwm.cpp.i

.PHONY : pwm.i

# target to preprocess a source file
pwm.cpp.i:
	$(MAKE) -f CMakeFiles/pwm.dir/build.make CMakeFiles/pwm.dir/pwm.cpp.i
.PHONY : pwm.cpp.i

pwm.s: pwm.cpp.s

.PHONY : pwm.s

# target to generate assembly for a file
pwm.cpp.s:
	$(MAKE) -f CMakeFiles/pwm.dir/build.make CMakeFiles/pwm.dir/pwm.cpp.s
.PHONY : pwm.cpp.s

xv11.o: xv11.cpp.o

.PHONY : xv11.o

# target to build an object file
xv11.cpp.o:
	$(MAKE) -f CMakeFiles/xv11_static.dir/build.make CMakeFiles/xv11_static.dir/xv11.cpp.o
	$(MAKE) -f CMakeFiles/xv11.dir/build.make CMakeFiles/xv11.dir/xv11.cpp.o
.PHONY : xv11.cpp.o

xv11.i: xv11.cpp.i

.PHONY : xv11.i

# target to preprocess a source file
xv11.cpp.i:
	$(MAKE) -f CMakeFiles/xv11_static.dir/build.make CMakeFiles/xv11_static.dir/xv11.cpp.i
	$(MAKE) -f CMakeFiles/xv11.dir/build.make CMakeFiles/xv11.dir/xv11.cpp.i
.PHONY : xv11.cpp.i

xv11.s: xv11.cpp.s

.PHONY : xv11.s

# target to generate assembly for a file
xv11.cpp.s:
	$(MAKE) -f CMakeFiles/xv11_static.dir/build.make CMakeFiles/xv11_static.dir/xv11.cpp.s
	$(MAKE) -f CMakeFiles/xv11.dir/build.make CMakeFiles/xv11.dir/xv11.cpp.s
.PHONY : xv11.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... printRPM"
	@echo "... printdata"
	@echo "... pwm"
	@echo "... xv11_static"
	@echo "... xv11"
	@echo "... printRPM.o"
	@echo "... printRPM.i"
	@echo "... printRPM.s"
	@echo "... printdata.o"
	@echo "... printdata.i"
	@echo "... printdata.s"
	@echo "... pwm.o"
	@echo "... pwm.i"
	@echo "... pwm.s"
	@echo "... xv11.o"
	@echo "... xv11.i"
	@echo "... xv11.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

