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
CMAKE_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-10.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Applications/MAMP/htdocs/voxelquest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Applications/MAMP/htdocs/voxelquest

# Include any dependencies generated for this target.
include CMakeFiles/voxelquest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/voxelquest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/voxelquest.dir/flags.make

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o: CMakeFiles/voxelquest.dir/flags.make
CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o: CompiledSource/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Applications/MAMP/htdocs/voxelquest/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o -c /Applications/MAMP/htdocs/voxelquest/CompiledSource/main.cpp

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Applications/MAMP/htdocs/voxelquest/CompiledSource/main.cpp > CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.i

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Applications/MAMP/htdocs/voxelquest/CompiledSource/main.cpp -o CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.s

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.requires:
.PHONY : CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.requires

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.provides: CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/voxelquest.dir/build.make CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.provides.build
.PHONY : CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.provides

CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.provides.build: CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o

# Object files for target voxelquest
voxelquest_OBJECTS = \
"CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o"

# External object files for target voxelquest
voxelquest_EXTERNAL_OBJECTS =

voxelquest: CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o
voxelquest: CMakeFiles/voxelquest.dir/build.make
voxelquest: /usr/local/lib/libboost_system.dylib
voxelquest: /usr/local/lib/libboost_filesystem.dylib
voxelquest: /usr/local/lib/libPocoFoundation.dylib
voxelquest: /usr/local/lib/libPocoNet.dylib
voxelquest: /usr/local/lib/libPocoUtil.dylib
voxelquest: CMakeFiles/voxelquest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable voxelquest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/voxelquest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/voxelquest.dir/build: voxelquest
.PHONY : CMakeFiles/voxelquest.dir/build

CMakeFiles/voxelquest.dir/requires: CMakeFiles/voxelquest.dir/CompiledSource/main.cpp.o.requires
.PHONY : CMakeFiles/voxelquest.dir/requires

CMakeFiles/voxelquest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/voxelquest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/voxelquest.dir/clean

CMakeFiles/voxelquest.dir/depend:
	cd /Applications/MAMP/htdocs/voxelquest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/MAMP/htdocs/voxelquest /Applications/MAMP/htdocs/voxelquest /Applications/MAMP/htdocs/voxelquest /Applications/MAMP/htdocs/voxelquest /Applications/MAMP/htdocs/voxelquest/CMakeFiles/voxelquest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/voxelquest.dir/depend

