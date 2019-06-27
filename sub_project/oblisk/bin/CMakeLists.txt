cmake_minimum_required(VERSION 3.0)


aux_source_directory(server SRV_SRC)

add_executable(oblisk_server ${SRV_SRC})