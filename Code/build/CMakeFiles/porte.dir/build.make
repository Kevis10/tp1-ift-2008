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
include CMakeFiles/porte.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/porte.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/porte.dir/flags.make

CMakeFiles/porte.dir/Porte.cpp.o: CMakeFiles/porte.dir/flags.make
CMakeFiles/porte.dir/Porte.cpp.o: ../Porte.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/porte.dir/Porte.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/porte.dir/Porte.cpp.o -c /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/Porte.cpp

CMakeFiles/porte.dir/Porte.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/porte.dir/Porte.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/Porte.cpp > CMakeFiles/porte.dir/Porte.cpp.i

CMakeFiles/porte.dir/Porte.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/porte.dir/Porte.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/Porte.cpp -o CMakeFiles/porte.dir/Porte.cpp.s

CMakeFiles/porte.dir/Porte.cpp.o.requires:

.PHONY : CMakeFiles/porte.dir/Porte.cpp.o.requires

CMakeFiles/porte.dir/Porte.cpp.o.provides: CMakeFiles/porte.dir/Porte.cpp.o.requires
	$(MAKE) -f CMakeFiles/porte.dir/build.make CMakeFiles/porte.dir/Porte.cpp.o.provides.build
.PHONY : CMakeFiles/porte.dir/Porte.cpp.o.provides

CMakeFiles/porte.dir/Porte.cpp.o.provides.build: CMakeFiles/porte.dir/Porte.cpp.o


# Object files for target porte
porte_OBJECTS = \
"CMakeFiles/porte.dir/Porte.cpp.o"

# External object files for target porte
porte_EXTERNAL_OBJECTS =

libporte.a: CMakeFiles/porte.dir/Porte.cpp.o
libporte.a: CMakeFiles/porte.dir/build.make
libporte.a: CMakeFiles/porte.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libporte.a"
	$(CMAKE_COMMAND) -P CMakeFiles/porte.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/porte.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/porte.dir/build: libporte.a

.PHONY : CMakeFiles/porte.dir/build

CMakeFiles/porte.dir/requires: CMakeFiles/porte.dir/Porte.cpp.o.requires

.PHONY : CMakeFiles/porte.dir/requires

CMakeFiles/porte.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/porte.dir/cmake_clean.cmake
.PHONY : CMakeFiles/porte.dir/clean

CMakeFiles/porte.dir/depend:
	cd /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build /home/bryan/Documents/projet/universite/Session1/IFT-2008/TP1/Code/build/CMakeFiles/porte.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/porte.dir/depend

