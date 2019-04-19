cmake_minimum_required(VERSION 3.0)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/target/debug/example)

link_libraries(
    dlagon
    pthread
)

add_subdirectory(client_socket)
add_subdirectory(cookie)
add_subdirectory(http)
add_subdirectory(json)
add_subdirectory(login)
add_subdirectory(server)
add_subdirectory(server_socket)
add_subdirectory(session)
# add_subdirectory(socket)