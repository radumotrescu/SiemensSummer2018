cmake_minimum_required(VERSION 2.8.9)
project(GenericProgramming)

include_directories( ${CMAKE_SOURCE_DIR}/src/DataStructures/include)
link_directories(${CMAKE_SOURCE_DIR}/src/DataStructures/src)

file(GLOB SOURCES "src/*.cpp")

add_executable(2.TemplateClassess ${SOURCES})
target_link_libraries(2.TemplateClassess DataStructures)