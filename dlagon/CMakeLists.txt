cmake_minimum_required(VERSION 3.0)

# 将src下所有源文件添加到变量LIBSRCS中
aux_source_directory(src LIBSRCS)
aux_source_directory(src/http LIBSRCS)
aux_source_directory(src/common LIBSRCS)
aux_source_directory(src/net LIBSRCS)
aux_source_directory(src/net/common LIBSRCS)
aux_source_directory(src/net/tcp LIBSRCS)
aux_source_directory(src/net/udp LIBSRCS)
aux_source_directory(src/server LIBSRCS)


# # 添加header库,但是从不使用,仅仅作为检查头文件的一个手段
# add_library(header dlagon/src/dlagon.cc)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/target/lib)


# 添加dlagon库
add_library(dlagon STATIC ${LIBSRCS})