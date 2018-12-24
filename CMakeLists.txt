cmake_minimum_required (VERSION 2.6)

PROJECT(dlagon)

include_directories(
    dlagon/include
)


aux_source_directory(dlagon/src LIBSRCS)
aux_source_directory(dlagon/src/http LIBSRCS)
aux_source_directory(dlagon/src/common LIBSRCS)
aux_source_directory(dlagon/src/net LIBSRCS)
aux_source_directory(dlagon/src/net/common LIBSRCS)

link_libraries(
    pthread
    gtest
    gmock
)

aux_source_directory(test TEST_SRCS)
aux_source_directory(test/http TEST_SRCS)

# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/bin)       #设置可执行文件的输出目录

# SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/lib)           #设置库文件的输出目录

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY target/)

add_library(dlagon STATIC ${LIBSRCS})

link_directories(
    build
)

aux_source_directory(example/socket EXAMPLE_SOCKET)

add_executable(test ${TEST_SRCS})
target_link_libraries(test dlagon pthread gtest gmock)

add_executable(exmp_sock ${EXAMPLE_SOCKET})
target_link_libraries(exmp_sock dlagon)


set (CMAKE_BUILD_TYPE Debug)

add_definitions(-Wall)