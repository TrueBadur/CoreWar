cmake_minimum_required(VERSION 3.14.2)
project(CoreWar C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-lncurses")
include_directories(libft/includes/ ./include data/)
include_directories(include)

aux_source_directory(src/asm src_asm)
aux_source_directory(src/vm src_vm)
aux_source_directory(src/ src)
aux_source_directory(src/visu src_visu)


add_executable(corewar ${src_vm} ${src_visu} ${src})
target_link_libraries(corewar ${PROJECT_SOURCE_DIR}/libft/lib/libft.a)

target_include_directories(corewar PUBLIC include/vm)

add_executable(asm ${src_asm} ${src})
target_link_libraries(asm ${PROJECT_SOURCE_DIR}/libft/lib/libft.a)

target_include_directories(asm PUBLIC include/asm)

