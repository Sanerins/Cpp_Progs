cmake_minimum_required(VERSION 3.17)
project(DoubleLinked)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(DoubleLinked main.cpp DoubleLinkedList.cpp DoubleLinkedList.h)