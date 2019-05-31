cmake_minimum_required(VERSION 3.0)

link_libraries(
   dlagon
   pthread
)

aux_source_directory(hello HELLO_SRC)

add_executable(hello ${HELLO_SRC})


aux_source_directory(function FNC_SRC)

add_executable(tcp_server ${FNC_SRC})


aux_source_directory(static STATIC_SRC)

add_executable(static ${STATIC_SRC})
