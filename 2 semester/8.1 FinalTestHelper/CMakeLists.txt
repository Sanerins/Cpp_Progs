cmake_minimum_required(VERSION 3.16.3)
project(tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(tree main.cpp BinarySearchTree.hpp Queue.hpp QueueArray.hpp QueueOverflow.hpp QueueUnderflow.hpp Stack.hpp StackArray.hpp StackOverflow.hpp StackUnderflow.hpp WrongQueueSize.hpp WrongStackSize.hpp)