cmake_minimum_required(VERSION 3.0)

link_libraries(
	gtest
	pthread
	dlagon
)

aux_source_directory(. SRCS)

aux_source_directory(dlagon SRCS)
aux_source_directory(dlagon/common SRCS)
aux_source_directory(dlagon/http SRCS)

add_compile_options(-g)

add_executable(test_main ${SRCS})
