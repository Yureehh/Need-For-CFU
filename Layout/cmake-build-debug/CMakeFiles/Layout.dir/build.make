# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Utente\Desktop\Need-For-CFU\Layout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Layout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Layout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Layout.dir/flags.make

CMakeFiles/Layout.dir/contorno.cpp.obj: CMakeFiles/Layout.dir/flags.make
CMakeFiles/Layout.dir/contorno.cpp.obj: ../contorno.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Layout.dir/contorno.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Layout.dir\contorno.cpp.obj -c C:\Users\Utente\Desktop\Need-For-CFU\Layout\contorno.cpp

CMakeFiles/Layout.dir/contorno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Layout.dir/contorno.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Utente\Desktop\Need-For-CFU\Layout\contorno.cpp > CMakeFiles\Layout.dir\contorno.cpp.i

CMakeFiles/Layout.dir/contorno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Layout.dir/contorno.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Utente\Desktop\Need-For-CFU\Layout\contorno.cpp -o CMakeFiles\Layout.dir\contorno.cpp.s

# Object files for target Layout
Layout_OBJECTS = \
"CMakeFiles/Layout.dir/contorno.cpp.obj"

# External object files for target Layout
Layout_EXTERNAL_OBJECTS =

Layout.exe: CMakeFiles/Layout.dir/contorno.cpp.obj
Layout.exe: CMakeFiles/Layout.dir/build.make
Layout.exe: CMakeFiles/Layout.dir/linklibs.rsp
Layout.exe: CMakeFiles/Layout.dir/objects1.rsp
Layout.exe: CMakeFiles/Layout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Layout.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Layout.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Layout.dir/build: Layout.exe

.PHONY : CMakeFiles/Layout.dir/build

CMakeFiles/Layout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Layout.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Layout.dir/clean

CMakeFiles/Layout.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Utente\Desktop\Need-For-CFU\Layout C:\Users\Utente\Desktop\Need-For-CFU\Layout C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug C:\Users\Utente\Desktop\Need-For-CFU\Layout\cmake-build-debug\CMakeFiles\Layout.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Layout.dir/depend
