cmake_minimum_required(VERSION 2.8)

project(PoachersFind)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

add_library(PoachersFind ver2.0/functions.cpp)

target_include_directories(PoachersFind PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(prog ver2.0/main.cpp ver2.0/functions.cpp)

target_link_libraries(prog PRIVATE PoachersFind)
