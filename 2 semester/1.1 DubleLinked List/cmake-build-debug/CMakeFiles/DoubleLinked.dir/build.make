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
CMAKE_COMMAND = "D:\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DoubleLinked.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DoubleLinked.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoubleLinked.dir/flags.make

CMakeFiles/DoubleLinked.dir/main.cpp.obj: CMakeFiles/DoubleLinked.dir/flags.make
CMakeFiles/DoubleLinked.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoubleLinked.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DoubleLinked.dir\main.cpp.obj -c "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\main.cpp"

CMakeFiles/DoubleLinked.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoubleLinked.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\main.cpp" > CMakeFiles\DoubleLinked.dir\main.cpp.i

CMakeFiles/DoubleLinked.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoubleLinked.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\main.cpp" -o CMakeFiles\DoubleLinked.dir\main.cpp.s

CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.obj: CMakeFiles/DoubleLinked.dir/flags.make
CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.obj: ../DoubleLinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DoubleLinked.dir\DoubleLinkedList.cpp.obj -c "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\DoubleLinkedList.cpp"

CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\DoubleLinkedList.cpp" > CMakeFiles\DoubleLinked.dir\DoubleLinkedList.cpp.i

CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\DoubleLinkedList.cpp" -o CMakeFiles\DoubleLinked.dir\DoubleLinkedList.cpp.s

# Object files for target DoubleLinked
DoubleLinked_OBJECTS = \
"CMakeFiles/DoubleLinked.dir/main.cpp.obj" \
"CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.obj"

# External object files for target DoubleLinked
DoubleLinked_EXTERNAL_OBJECTS =

DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/main.cpp.obj
DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/DoubleLinkedList.cpp.obj
DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/build.make
DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/linklibs.rsp
DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/objects1.rsp
DoubleLinked.exe: CMakeFiles/DoubleLinked.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DoubleLinked.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DoubleLinked.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoubleLinked.dir/build: DoubleLinked.exe

.PHONY : CMakeFiles/DoubleLinked.dir/build

CMakeFiles/DoubleLinked.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DoubleLinked.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DoubleLinked.dir/clean

CMakeFiles/DoubleLinked.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List" "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List" "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug" "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug" "D:\GitHub\Cpp_Progs\2 semester\1.1 DubleLinked List\cmake-build-debug\CMakeFiles\DoubleLinked.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DoubleLinked.dir/depend

