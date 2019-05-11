cmake_minimum_required(VERSION 3.0)


aux_source_directory(. SRC)
aux_source_directory(interface SRC)
aux_source_directory(http SRC)
aux_source_directory(net SRC)
aux_source_directory(net/tcp SRC)
aux_source_directory(web SRC)

add_library(dlagon ${SRC})




