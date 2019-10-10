cmake_minimum_required(VERSION 3.14.2)
project(CoreWar C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libft)
include_directories(libft/include)

include_directories(include)

aux_source_directory(src/asm src_asm)
aux_source_directory(src/vm src_vm)

add_executable(CoreWar ${src_vm})
target_link_libraries(CoreWar libft)

add_executable(asm ${src_asm})
target_link_libraries(asm libft)