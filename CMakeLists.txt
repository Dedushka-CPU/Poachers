cmake_minimum_required(VERSION 2.8)

project(PoachersFind)

set(CMAKE_CXX_STANDARD 17)

add_executable(PoachersFind ver2.0/main.cpp ver2.0/functions.cpp)
add_executable(PoachersFindTests tests/test.cpp tests/functions.cpp)

