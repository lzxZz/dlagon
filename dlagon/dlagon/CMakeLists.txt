cmake_minimum_required(VERSION 3.0)


aux_source_directory(. SRCS)
aux_source_directory(interface SRCS)

add_library(dlagon ${SRCS})
