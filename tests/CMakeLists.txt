cmake_minimum_required(VERSION 3.0)


link_libraries(
    dlagon 
    gtest 
    pthread
)




set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/target/debug/test/)


aux_source_directory(. SRCS)
aux_source_directory(http SRCS)

add_executable(tests ${SRCS})
