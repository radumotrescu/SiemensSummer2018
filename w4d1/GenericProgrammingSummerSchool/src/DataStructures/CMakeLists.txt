cmake_minimum_required(VERSION 2.8.9)
project(GenericProgramming)

include_directories(${CMAKE_SOURCE_DIR}/src/DataStructures/include)

add_library(DataStructures src/Amount.cpp src/Complex.cpp include/Amount.h include/Complex.h)