cmake_minimum_required(VERSION 3.13)
project(Aurora)

set(CMAKE_CXX_STANDARD 14)

add_executable(Aurora main.cpp)

add_executable(CRectangle cpp01/CRectangle.cpp cpp01/CRectangle.h)
add_executable(CEmployee cpp01/CEmployee.cpp)
add_executable(a_cpp_01 cpp01/cpp_01.cpp)
add_executable(a_cpp_02 cpp01/cpp_02.cpp)
add_executable(a_cpp_03 cpp01/cpp_03.cpp)
add_executable(a_cpp_04 cpp01/cpp_04.cpp)
add_executable(a_cpp_05 cpp01/cpp_05.cpp)
add_executable(bank bank/bank.cpp bank/bank.h bank/stdafx.h bank/stdafx.cpp bank/targetver.h )

add_executable(CSample alpha/CSample.cpp)
add_executable(start alpha/start.cpp)
#add_executable(wmain wmain/wmain.cpp)
add_executable(alpha_cpp_01 alpha/cpp_01.cpp)
add_executable(CRectangle01 alpha/CRectangle.cpp)
add_executable(CCar alpha/CCar.cpp)
add_executable(Complex alpha/Complex.cpp)

add_executable(stl_01 stl/stl_01.cpp)

#http/MoHttp.cpp http/MoHttp.h
add_executable(http http/main.cpp http/mongoose.c http/mongoose.h http/basic_http.cpp http/basic_http.h)

#add_executable(wmain01 wmain/wmain01.cpp)

add_executable(cpp_02_test_swap cpp02/test_swap.cpp)
add_executable(cpp_02_test_struct cpp02/test_struct.cpp)
add_executable(cpp_02_test_refferce cpp02/test_refferce.cpp)
add_executable(cpp_02_test_template cpp02/test_template.cpp)
add_executable(cpp_02_test_template_1 cpp02/test_template_1.cpp)
add_executable(cpp_02_test_template_2 cpp02/test_template_2.cpp)
add_executable(cpp_02_test_class cpp02/test_class.cpp)
add_executable(cpp_02_test_virtual cpp02/test_virtual.cpp)
add_executable(cpp_02_test_virtual_1 cpp02/test_virtual_1.cpp)
add_executable(cpp_02_test_execise cpp02/execise.cpp)
add_executable(cpp_02_test_typedef cpp02/test_typedef.cpp)
add_executable(cpp_02_test_constructor cpp02/test_constructor.cpp)
add_executable(cpp_02_test_friend cpp02/test_friend.cpp)
add_executable(cpp_02_test_inherit cpp02/test_inherit.cpp)
add_executable(cpp_02_test_inherit_1 cpp02/test_inherit_1.cpp)
add_executable(cpp_02_test_operator cpp02/test_operator.cpp)
add_executable(cpp_02_test_operator_1 cpp02/test_operator_1.cpp)
add_executable(cpp_02_test_operator_2 cpp02/test_operator_2.cpp)
add_executable(cpp_02_test_polymorphic cpp02/test_polymorphic.cpp)
add_executable(cpp_02_test_stream cpp02/test_stream.cpp)
add_executable(cpp_02_test_exception cpp02/test_exception.cpp)
add_executable(cpp_02_test_exception_1 cpp02/test_exception_1.cpp)
add_executable(cpp_02_test_namespace cpp02/test_namespace.cpp)
add_executable(cpp_02_test_preprocessed cpp02/test_preprocessed.cpp)
add_executable(cpp_02_test_signal cpp02/test_signal.cpp)
add_executable(cpp_02_test_signal_1 cpp02/test_signal_1.cpp)


add_executable(cpp_02_test_thread cpp02/test_thread.cpp)
# clion 编译支持 pthread，需要加在 add_executable 后面
find_package(Threads REQUIRED)
target_link_libraries(cpp_02_test_thread Threads::Threads)


add_executable(cpp_02_test_thread_1 cpp02/test_thread_1.cpp)
target_link_libraries(cpp_02_test_thread_1 Threads::Threads)

add_executable(cpp_02_test_thread_2 cpp02/test_thread_2.cpp)
target_link_libraries(cpp_02_test_thread_2 Threads::Threads)

add_executable(cpp_02_test_thread_3 cpp02/test_thread_3.cpp)
target_link_libraries(cpp_02_test_thread_3 Threads::Threads)

add_executable(cpp_02_test_thread_4 cpp02/test_thread_4.cpp)
target_link_libraries(cpp_02_test_thread_4 Threads::Threads)

add_executable(cpp_02_test_batch_thread cpp02/test_batch_thread.cpp)
target_link_libraries(cpp_02_test_batch_thread Threads::Threads)

