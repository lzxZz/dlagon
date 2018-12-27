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



add_executable(test ${TEST_SRCS})
target_link_libraries(test dlagon pthread gtest gmock)


aux_source_directory(example/socket/client EXMP_CLIENT)
aux_source_directory(example/client_socket/ EXMP_CLIENT_SOCK_CLIENT)
aux_source_directory(example/server_socket/ EXMP_SERVER_SOCK_SERVER)

aux_source_directory(example/socket/server EXMP_SERVER)
aux_source_directory(example/socket/http EXMP_HTTP)

# add_subdirectory(example/socket/client)



add_executable(daytime_client ${EXMP_CLIENT})
add_executable(daytime_client1 ${EXMP_CLIENT_SOCK_CLIENT})
add_executable(daytime_server1 ${EXMP_SERVER_SOCK_SERVER})
add_executable(daytime_server ${EXMP_SERVER})
add_executable(http ${EXMP_HTTP})

target_link_libraries(daytime_client1 dlagon)
target_link_libraries(daytime_client dlagon)
target_link_libraries(daytime_server dlagon)
target_link_libraries(daytime_server1 dlagon)
target_link_libraries(http dlagon)


set (CMAKE_BUILD_TYPE Debug)

add_definitions(-Wall)