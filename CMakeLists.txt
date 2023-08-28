cmake_minimum_required(VERSION 3.26)
project(AlgorithmImplementation)

set(CMAKE_CXX_STANDARD 14)
#add_definitions(-DINSERTION_SORT_TEST=1)
#add_definitions(-DMERGESORT_TEST=1)
#add_definitions(-DBUBBLESORT_TEST=1)

include_directories(Cpp/Sort)

add_executable(AlgorithmImplementation
        Cpp/Test.cpp
        Cpp/Test.h
        Cpp/Sort.h
)
