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
CMAKE_SOURCE_DIR = /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_porte.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_porte.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_porte.dir/flags.make

test/CMakeFiles/test_porte.dir/test_porte.cpp.o: test/CMakeFiles/test_porte.dir/flags.make
test/CMakeFiles/test_porte.dir/test_porte.cpp.o: ../test/test_porte.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_porte.dir/test_porte.cpp.o"
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_porte.dir/test_porte.cpp.o -c /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/test/test_porte.cpp

test/CMakeFiles/test_porte.dir/test_porte.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_porte.dir/test_porte.cpp.i"
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/test/test_porte.cpp > CMakeFiles/test_porte.dir/test_porte.cpp.i

test/CMakeFiles/test_porte.dir/test_porte.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_porte.dir/test_porte.cpp.s"
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/test/test_porte.cpp -o CMakeFiles/test_porte.dir/test_porte.cpp.s

test/CMakeFiles/test_porte.dir/test_porte.cpp.o.requires:

.PHONY : test/CMakeFiles/test_porte.dir/test_porte.cpp.o.requires

test/CMakeFiles/test_porte.dir/test_porte.cpp.o.provides: test/CMakeFiles/test_porte.dir/test_porte.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_porte.dir/build.make test/CMakeFiles/test_porte.dir/test_porte.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_porte.dir/test_porte.cpp.o.provides

test/CMakeFiles/test_porte.dir/test_porte.cpp.o.provides.build: test/CMakeFiles/test_porte.dir/test_porte.cpp.o


# Object files for target test_porte
test_porte_OBJECTS = \
"CMakeFiles/test_porte.dir/test_porte.cpp.o"

# External object files for target test_porte
test_porte_EXTERNAL_OBJECTS =

test/test_porte: test/CMakeFiles/test_porte.dir/test_porte.cpp.o
test/test_porte: test/CMakeFiles/test_porte.dir/build.make
test/test_porte: libporte.a
test/test_porte: libpiece.a
test/test_porte: test/CMakeFiles/test_porte.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_porte"
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_porte.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_porte.dir/build: test/test_porte

.PHONY : test/CMakeFiles/test_porte.dir/build

test/CMakeFiles/test_porte.dir/requires: test/CMakeFiles/test_porte.dir/test_porte.cpp.o.requires

.PHONY : test/CMakeFiles/test_porte.dir/requires

test/CMakeFiles/test_porte.dir/clean:
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_porte.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_porte.dir/clean

test/CMakeFiles/test_porte.dir/depend:
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/test /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/test/CMakeFiles/test_porte.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_porte.dir/depend

