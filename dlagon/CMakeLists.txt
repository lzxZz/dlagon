cmake_minimum_required(VERSION 3.0)

project(dlagon CXX)

aux_source_directory(. SRCS)
aux_source_directory(net SRCS)


add_library(dlagon STATIC ${SRCS})



SET_TARGET_PROPERTIES(dlagon PROPERTIES LINKER_LANGUAGE CXX)