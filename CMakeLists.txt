cmake_minimum_required(VERSION 3.8)
project(Project1_v2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c functions.h functions.c)
add_executable(Project1_v2 ${SOURCE_FILES})