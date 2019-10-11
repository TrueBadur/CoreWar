cmake_minimum_required(VERSION 3.14.2)
project(CoreWar C)

set(CMAKE_C_STANDARD 99)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using
include_directories(libft/includes/ ./include) # directory with headers
#link_directories(/usr/local/lib libft/lib)
#FILE(GLOB LIBFT_SRCS ./libft/std_lib/*.c ./libft/std_lib/printf/*.c)

#AUX_SOURCE_DIRECTORY(libft/std_lib/liblist/ )

#add_subdirectory(libft)
#include_directories(libft/include)

include_directories(include)

aux_source_directory(src/asm src_asm)
aux_source_directory(src/vm src_vm)

#include(FindPkgConfig)
#find_package(ft REQUIRED)
#include_directories(${ft_INCLUDE_DIR})

add_executable(corewar ${src_vm})
target_link_libraries(corewar /Users/ehugh-be/Documents/CoreWar/libft/lib/libft.a)
target_include_directories(corewar PUBLIC include/vm)

add_executable(asm ${src_asm})
target_link_libraries(asm /Users/ehugh-be/Documents/CoreWar/libft/lib/libft.a)
target_include_directories(asm PUBLIC include/asm)

