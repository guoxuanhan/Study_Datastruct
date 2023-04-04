cmake_minimum_required(VERSION 3.21)
project(Study_Datastruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(Study_Datastruct main.cpp src/List/single_list.cpp src/List/single_list.h test/sing_list_test.cpp src/Vector/vector.cpp src/Vector/vector.h)
