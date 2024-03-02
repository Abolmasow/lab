cmake_minimum_required(VERSION 3.26)
project(untitled6 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled6 main.c
        cmake-build-debug/libs/algorithms/array/array.c
        cmake-build-debug/libs/algorithms/array/array.h
        cmake-build-debug/libs/algorithms/algorithm.c
        cmake-build-debug/libs/algorithms/algorithm.h
        cmake-build-debug/libs/data_structures/bitset/bitset.c
        cmake-build-debug/libs/data_structures/bitset/bitset.h
        libs/data_structures/unordered_set/unordered_set.c
        libs/data_structures/unordered_set/unordered_set.h
        libs/data_structures/ordered_set/ordered_set.c
        libs/data_structures/ordered_set/ordered_set.h
        libs/data_structures/ordered_set/ordered_set.c)
add_subdirectory(libs)
target_link_libraries(untitled6 data_structures)
target_link_libraries(untited6 algorithms)