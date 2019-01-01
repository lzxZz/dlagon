# 设置cmake的最小版本
cmake_minimum_required (VERSION 2.6)

# 设置项目名称
PROJECT(dlagon)

# 设置编译时头文件搜索位置
include_directories(
    dlagon/include
)

# 将src下所有源文件添加到变量LIBSRCS中
aux_source_directory(dlagon/src LIBSRCS)
aux_source_directory(dlagon/src/http LIBSRCS)
aux_source_directory(dlagon/src/common LIBSRCS)
aux_source_directory(dlagon/src/net LIBSRCS)
aux_source_directory(dlagon/src/net/common LIBSRCS)
aux_source_directory(dlagon/src/net/tcp LIBSRCS)
aux_source_directory(dlagon/src/net/udp LIBSRCS)

# 添加header库,但是从不使用,仅仅作为检查头文件的一个手段
add_library(header dlagon/src/dlagon.cc)

# 设置链接库
link_libraries(
    pthread
    gtest
    gmock
)

# 设置测试代码源文件路径
aux_source_directory(test TEST_SRCS)
aux_source_directory(test/http TEST_SRCS)

# 设置生成输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY target/)

# 添加dlagon库
add_library(dlagon STATIC ${LIBSRCS})

# 设置链接库的搜索位置
link_directories(
    build
)


# 添加测试可执行文件
add_executable(test ${TEST_SRCS})
# 设置test依赖的库
target_link_libraries(test dlagon pthread gtest gmock)


# 设置示例代码源文件
aux_source_directory(example/socket/client EXMP_CLIENT)
aux_source_directory(example/client_socket/ EXMP_CLIENT_SOCK_CLIENT)
aux_source_directory(example/server_socket/ EXMP_SERVER_SOCK_SERVER)
aux_source_directory(example/socket/server EXMP_SERVER)
aux_source_directory(example/socket/http EXMP_HTTP_HELLO)

aux_source_directory(example/http EXMP_HTTP_BASIC)



# 添加示例代码可执行文件
add_executable(daytime_client ${EXMP_CLIENT})
add_executable(daytime_client1 ${EXMP_CLIENT_SOCK_CLIENT})
add_executable(daytime_server1 ${EXMP_SERVER_SOCK_SERVER})
add_executable(daytime_server ${EXMP_SERVER})
add_executable(http ${EXMP_HTTP_HELLO})
add_executable(http_basic ${EXMP_HTTP_BASIC})

# 设置示例代码依赖库
target_link_libraries(daytime_client1 dlagon )
target_link_libraries(daytime_client dlagon )
target_link_libraries(daytime_server dlagon )
target_link_libraries(daytime_server1 dlagon )
target_link_libraries(http dlagon )
target_link_libraries(http_basic dlagon)

# 设置cmake的构建类型为debug
set (CMAKE_BUILD_TYPE Debug)

# 添加编译选项 -Wall
add_definitions(-Wall)