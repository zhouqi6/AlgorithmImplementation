cmake_minimum_required(VERSION 3.26)
project(AlgorithmImplementation)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-DALGORITHM_IMPLEMENTATION_INSERTION_SORT_TEST=1)

include_directories(Cpp/Sort)

add_executable(AlgorithmImplementation
        Cpp/Sort/InsertionSort.cpp
        Cpp/Sort/InsertionSort.h
        Cpp/Test.cpp
        Cpp/Test.h
)
