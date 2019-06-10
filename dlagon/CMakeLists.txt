cmake_minimum_required(VERSION 3.0)


add_compile_options(-g -Wall)


aux_source_directory(. SRC)
aux_source_directory(common SRC)
aux_source_directory(error SRC)
aux_source_directory(interface SRC)
aux_source_directory(http SRC)
aux_source_directory(http/midware SRC)
aux_source_directory(http/midware/static SRC)
aux_source_directory(http/midware/route SRC)
aux_source_directory(net SRC)
aux_source_directory(net/tcp SRC)
aux_source_directory(web SRC)

add_library(dlagon ${SRC})

link_libraries(
    dlagon
)

add_executable(run test.cc)

