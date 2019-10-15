cmake_minimum_required(VERSION 3.13)
project(CPPHub)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(aurora)
add_subdirectory(f)

add_executable(cpp_01 cpp/cpp_01.cpp)
add_executable(cpp_02 cpp/cpp_02.cpp)
add_executable(cpp_03 cpp/cpp_03.cpp)
add_executable(cpp_04 cpp/cpp_04.cpp)
add_executable(cpp_05 cpp/cpp_05.cpp)
add_executable(cpp_06 cpp/cpp_06.cpp)
add_executable(cpp_07 cpp/cpp_07.cpp)
add_executable(cpp_08 cpp/cpp_08.cpp)
add_executable(cpp_09 cpp/cpp_09.cpp)
add_executable(cpp_10 cpp/cpp_10.cpp)
add_executable(cpp_11 cpp/cpp_11.cpp)
add_executable(cpp_12 cpp/cpp_12.cpp)
add_executable(cpp_13 cpp/cpp_13.cpp)
add_executable(cpp_14 cpp/cpp_14.cpp)
add_executable(cpp_15 cpp/cpp_15.cpp)
add_executable(cpp_16 cpp/cpp_16.cpp)
add_executable(cpp_17 cpp/cpp_17.cpp)


add_executable(01 a/plane.cpp a/plane.h a/Jet.cpp a/Jet.h a/01.cpp a/Copter.cpp a/Copter.h)
add_executable(02  a/02.cpp)
add_executable(03  a/03.cpp)
add_executable(04  a/04.cpp)
add_executable(05  a/05.cpp)
add_executable(io  a/io.cpp)

add_executable(b_main  b/main.cpp)
add_executable(b_cpp_01  b/cpp_01.cpp)
add_executable(b_cpp_02  b/cpp_02.cpp)
add_executable(b_strc_ref  b/strc_ref.cpp)
add_executable(usetime3  b/mytime3.cpp b/mytime3.h b/usetime3.cpp)



add_executable(c_cpp_01  c/cpp_01.cpp)
add_executable(c_cpp_image  c/handle_image.cpp c/stb_image.h)

add_executable(test_namespace d/test_namespace.cpp)
add_executable(d_main d/main.cpp)

add_executable(d_IntArray d/IntArrayRC.cpp d/IntArrayRC.h d/IntArray.h d/IntArray.cpp d/main1.cpp)
add_executable(d_IntSortedArray d/IntSortedArray.h d/IntSortedArray.cpp)
add_executable(d_Array d/Array.cpp d/Array.h d/main_array.cpp)
add_executable(trycatch trycatch/main.cpp  )

add_executable(e_01 e/01.cpp)
add_executable(e_02 e/02.cpp)
add_executable(e_c1 e/c1.cpp)
