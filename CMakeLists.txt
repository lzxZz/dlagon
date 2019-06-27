cmake_minimum_required(VERSION 3.0)

project(dlagon CXX)

add_compile_options(-Wall -g)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(dlagon)

add_subdirectory(test)

add_subdirectory(example)


add_subdirectory(sub_project)