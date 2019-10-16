cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 14)

link_libraries(ws2_32)

add_executable(f_01 f_01.cpp)
add_executable(f_02 f_02.cpp)
add_executable(f_03 f_03.cpp)


add_executable(icmp_ping icmp_ping.cpp)
add_executable(tracert tracert.cpp)
add_executable(tracert_1 tracert_1.cpp)


