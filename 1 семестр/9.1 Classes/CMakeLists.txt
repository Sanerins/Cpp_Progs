cmake_minimum_required(VERSION 3.17)
project(9_1_Classes)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(9_1_Classes main.cpp Array.h MyString.h MyString.cpp Dish.h Cuisine.h Dish.cpp Cuisine.cpp Exceptions.h)