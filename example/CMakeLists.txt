cmake_minimum_required(VERSION 3.0)

link_libraries(
   dlagon
)

# aux_source_directory(hello HELLO_SRC)

# add_executable(hello ${HELLO_SRC})


aux_source_directory(function FNC_SRC)

add_executable(tcp_server function/tcp_server.cc)

target_link_libraries(tcp_server dlagon)