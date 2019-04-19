cmake_minimum_required(VERSION 3.0)

project(dlagon CXX)

aux_source_directory(. SRCS)
aux_source_directory(socket SRCS)

link_libraries(
    dlagon
    gtest
    pthread
)


add_executable(test_main ${SRCS})