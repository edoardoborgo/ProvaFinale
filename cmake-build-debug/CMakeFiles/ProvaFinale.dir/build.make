# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/albertopenzo/CLionProjects/ProvaFinale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProvaFinale.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProvaFinale.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProvaFinale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProvaFinale.dir/flags.make

CMakeFiles/ProvaFinale.dir/src/main.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/main.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/main.cpp
CMakeFiles/ProvaFinale.dir/src/main.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProvaFinale.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/main.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/main.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/main.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/main.cpp

CMakeFiles/ProvaFinale.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/main.cpp > CMakeFiles/ProvaFinale.dir/src/main.cpp.i

CMakeFiles/ProvaFinale.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/main.cpp -o CMakeFiles/ProvaFinale.dir/src/main.cpp.s

CMakeFiles/ProvaFinale.dir/src/Player.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/Player.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/Player.cpp
CMakeFiles/ProvaFinale.dir/src/Player.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProvaFinale.dir/src/Player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/Player.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/Player.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/Player.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/Player.cpp

CMakeFiles/ProvaFinale.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/Player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/Player.cpp > CMakeFiles/ProvaFinale.dir/src/Player.cpp.i

CMakeFiles/ProvaFinale.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/Player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/Player.cpp -o CMakeFiles/ProvaFinale.dir/src/Player.cpp.s

CMakeFiles/ProvaFinale.dir/src/Board.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/Board.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/Board.cpp
CMakeFiles/ProvaFinale.dir/src/Board.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProvaFinale.dir/src/Board.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/Board.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/Board.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/Board.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/Board.cpp

CMakeFiles/ProvaFinale.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/Board.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/Board.cpp > CMakeFiles/ProvaFinale.dir/src/Board.cpp.i

CMakeFiles/ProvaFinale.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/Board.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/Board.cpp -o CMakeFiles/ProvaFinale.dir/src/Board.cpp.s

CMakeFiles/ProvaFinale.dir/src/Human.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/Human.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/Human.cpp
CMakeFiles/ProvaFinale.dir/src/Human.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProvaFinale.dir/src/Human.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/Human.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/Human.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/Human.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/Human.cpp

CMakeFiles/ProvaFinale.dir/src/Human.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/Human.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/Human.cpp > CMakeFiles/ProvaFinale.dir/src/Human.cpp.i

CMakeFiles/ProvaFinale.dir/src/Human.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/Human.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/Human.cpp -o CMakeFiles/ProvaFinale.dir/src/Human.cpp.s

CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/Pc.cpp
CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/Pc.cpp

CMakeFiles/ProvaFinale.dir/src/Pc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/Pc.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/Pc.cpp > CMakeFiles/ProvaFinale.dir/src/Pc.cpp.i

CMakeFiles/ProvaFinale.dir/src/Pc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/Pc.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/Pc.cpp -o CMakeFiles/ProvaFinale.dir/src/Pc.cpp.s

CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardManager.cpp
CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardManager.cpp

CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardManager.cpp > CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.i

CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardManager.cpp -o CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.s

CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxBlank.cpp
CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxBlank.cpp

CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxBlank.cpp > CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.i

CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxBlank.cpp -o CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.s

CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o: CMakeFiles/ProvaFinale.dir/flags.make
CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o: /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxProperty.cpp
CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o: CMakeFiles/ProvaFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o -MF CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o.d -o CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o -c /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxProperty.cpp

CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxProperty.cpp > CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.i

CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertopenzo/CLionProjects/ProvaFinale/src/BoardBoxProperty.cpp -o CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.s

# Object files for target ProvaFinale
ProvaFinale_OBJECTS = \
"CMakeFiles/ProvaFinale.dir/src/main.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/Player.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/Board.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/Human.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o" \
"CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o"

# External object files for target ProvaFinale
ProvaFinale_EXTERNAL_OBJECTS =

ProvaFinale: CMakeFiles/ProvaFinale.dir/src/main.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/Player.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/Board.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/Human.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/Pc.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/BoardManager.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/BoardBoxBlank.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/src/BoardBoxProperty.cpp.o
ProvaFinale: CMakeFiles/ProvaFinale.dir/build.make
ProvaFinale: CMakeFiles/ProvaFinale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ProvaFinale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProvaFinale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProvaFinale.dir/build: ProvaFinale
.PHONY : CMakeFiles/ProvaFinale.dir/build

CMakeFiles/ProvaFinale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProvaFinale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProvaFinale.dir/clean

CMakeFiles/ProvaFinale.dir/depend:
	cd /Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/albertopenzo/CLionProjects/ProvaFinale /Users/albertopenzo/CLionProjects/ProvaFinale /Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug /Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug /Users/albertopenzo/CLionProjects/ProvaFinale/cmake-build-debug/CMakeFiles/ProvaFinale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProvaFinale.dir/depend
