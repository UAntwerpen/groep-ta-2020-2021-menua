# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/flags.make

CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.obj: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/flags.make
CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.obj"
	D:\QT\Tools\mingw810_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\main.cpp.obj -c C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\main.cpp

CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.i"
	D:\QT\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\main.cpp > CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\main.cpp.i

CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.s"
	D:\QT\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\main.cpp -o CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\main.cpp.s

# Object files for target TAProject2021_MenuaHovhannisyan
TAProject2021_MenuaHovhannisyan_OBJECTS = \
"CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.obj"

# External object files for target TAProject2021_MenuaHovhannisyan
TAProject2021_MenuaHovhannisyan_EXTERNAL_OBJECTS =

TAProject2021_MenuaHovhannisyan.exe: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/main.cpp.obj
TAProject2021_MenuaHovhannisyan.exe: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/build.make
TAProject2021_MenuaHovhannisyan.exe: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/linklibs.rsp
TAProject2021_MenuaHovhannisyan.exe: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/objects1.rsp
TAProject2021_MenuaHovhannisyan.exe: CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TAProject2021_MenuaHovhannisyan.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/build: TAProject2021_MenuaHovhannisyan.exe

.PHONY : CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/build

CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/clean

CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug C:\Users\Menua\Documents\GitHub\groep-ta-2020-2021-menua\cmake-build-debug\CMakeFiles\TAProject2021_MenuaHovhannisyan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TAProject2021_MenuaHovhannisyan.dir/depend

