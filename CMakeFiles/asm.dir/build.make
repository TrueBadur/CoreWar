# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /private/var/folders/zz/zyxvpxvq6csfxvn_n00012xm0008qd/T/AppTranslocation/FAA46983-DBA0-4BBC-BC25-83E3AA91287F/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/zz/zyxvpxvq6csfxvn_n00012xm0008qd/T/AppTranslocation/FAA46983-DBA0-4BBC-BC25-83E3AA91287F/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/blomo/corawara

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/blomo/corawara

# Include any dependencies generated for this target.
include CMakeFiles/asm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asm.dir/flags.make

CMakeFiles/asm.dir/src/asm/assembler.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/assembler.c.o: src/asm/assembler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/asm.dir/src/asm/assembler.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/assembler.c.o   -c /Users/blomo/corawara/src/asm/assembler.c

CMakeFiles/asm.dir/src/asm/assembler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/assembler.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/assembler.c > CMakeFiles/asm.dir/src/asm/assembler.c.i

CMakeFiles/asm.dir/src/asm/assembler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/assembler.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/assembler.c -o CMakeFiles/asm.dir/src/asm/assembler.c.s

CMakeFiles/asm.dir/src/asm/champ_generator.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/champ_generator.c.o: src/asm/champ_generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/asm.dir/src/asm/champ_generator.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/champ_generator.c.o   -c /Users/blomo/corawara/src/asm/champ_generator.c

CMakeFiles/asm.dir/src/asm/champ_generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/champ_generator.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/champ_generator.c > CMakeFiles/asm.dir/src/asm/champ_generator.c.i

CMakeFiles/asm.dir/src/asm/champ_generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/champ_generator.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/champ_generator.c -o CMakeFiles/asm.dir/src/asm/champ_generator.c.s

CMakeFiles/asm.dir/src/asm/disassembler.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/disassembler.c.o: src/asm/disassembler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/asm.dir/src/asm/disassembler.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/disassembler.c.o   -c /Users/blomo/corawara/src/asm/disassembler.c

CMakeFiles/asm.dir/src/asm/disassembler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/disassembler.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/disassembler.c > CMakeFiles/asm.dir/src/asm/disassembler.c.i

CMakeFiles/asm.dir/src/asm/disassembler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/disassembler.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/disassembler.c -o CMakeFiles/asm.dir/src/asm/disassembler.c.s

CMakeFiles/asm.dir/src/asm/lexer.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/lexer.c.o: src/asm/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/asm.dir/src/asm/lexer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/lexer.c.o   -c /Users/blomo/corawara/src/asm/lexer.c

CMakeFiles/asm.dir/src/asm/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/lexer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/lexer.c > CMakeFiles/asm.dir/src/asm/lexer.c.i

CMakeFiles/asm.dir/src/asm/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/lexer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/lexer.c -o CMakeFiles/asm.dir/src/asm/lexer.c.s

CMakeFiles/asm.dir/src/asm/main.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/main.c.o: src/asm/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/asm.dir/src/asm/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/main.c.o   -c /Users/blomo/corawara/src/asm/main.c

CMakeFiles/asm.dir/src/asm/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/main.c > CMakeFiles/asm.dir/src/asm/main.c.i

CMakeFiles/asm.dir/src/asm/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/main.c -o CMakeFiles/asm.dir/src/asm/main.c.s

CMakeFiles/asm.dir/src/asm/read_args.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/read_args.c.o: src/asm/read_args.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/asm.dir/src/asm/read_args.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/read_args.c.o   -c /Users/blomo/corawara/src/asm/read_args.c

CMakeFiles/asm.dir/src/asm/read_args.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/read_args.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/read_args.c > CMakeFiles/asm.dir/src/asm/read_args.c.i

CMakeFiles/asm.dir/src/asm/read_args.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/read_args.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/read_args.c -o CMakeFiles/asm.dir/src/asm/read_args.c.s

CMakeFiles/asm.dir/src/asm/writer.c.o: CMakeFiles/asm.dir/flags.make
CMakeFiles/asm.dir/src/asm/writer.c.o: src/asm/writer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/asm.dir/src/asm/writer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asm.dir/src/asm/writer.c.o   -c /Users/blomo/corawara/src/asm/writer.c

CMakeFiles/asm.dir/src/asm/writer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asm.dir/src/asm/writer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/blomo/corawara/src/asm/writer.c > CMakeFiles/asm.dir/src/asm/writer.c.i

CMakeFiles/asm.dir/src/asm/writer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asm.dir/src/asm/writer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/blomo/corawara/src/asm/writer.c -o CMakeFiles/asm.dir/src/asm/writer.c.s

# Object files for target asm
asm_OBJECTS = \
"CMakeFiles/asm.dir/src/asm/assembler.c.o" \
"CMakeFiles/asm.dir/src/asm/champ_generator.c.o" \
"CMakeFiles/asm.dir/src/asm/disassembler.c.o" \
"CMakeFiles/asm.dir/src/asm/lexer.c.o" \
"CMakeFiles/asm.dir/src/asm/main.c.o" \
"CMakeFiles/asm.dir/src/asm/read_args.c.o" \
"CMakeFiles/asm.dir/src/asm/writer.c.o"

# External object files for target asm
asm_EXTERNAL_OBJECTS =

asm: CMakeFiles/asm.dir/src/asm/assembler.c.o
asm: CMakeFiles/asm.dir/src/asm/champ_generator.c.o
asm: CMakeFiles/asm.dir/src/asm/disassembler.c.o
asm: CMakeFiles/asm.dir/src/asm/lexer.c.o
asm: CMakeFiles/asm.dir/src/asm/main.c.o
asm: CMakeFiles/asm.dir/src/asm/read_args.c.o
asm: CMakeFiles/asm.dir/src/asm/writer.c.o
asm: CMakeFiles/asm.dir/build.make
asm: libft/lib/libft.a
asm: CMakeFiles/asm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/blomo/corawara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable asm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asm.dir/build: asm

.PHONY : CMakeFiles/asm.dir/build

CMakeFiles/asm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asm.dir/clean

CMakeFiles/asm.dir/depend:
	cd /Users/blomo/corawara && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/blomo/corawara /Users/blomo/corawara /Users/blomo/corawara /Users/blomo/corawara /Users/blomo/corawara/CMakeFiles/asm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asm.dir/depend

