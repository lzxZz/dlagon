cmake_minimum_required(VERSION 3.0)

link_libraries(
	gtest
	pthread
	dlagon
)

aux_source_directory(. SRCS)

aux_source_directory(dlagon SRCS)

add_executable(test_main ${SRCS})
