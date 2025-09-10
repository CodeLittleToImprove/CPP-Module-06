cmake_minimum_required(VERSION 3.30)
project(cpp06)

set(CMAKE_CXX_STANDARD 98)


add_executable(cpp06_ex00
        ex00/ScalarConverter.cpp
        ex00/ScalarConverter.hpp
        ex00/main.cpp
        ex00/converters.cpp
        ex00/printers.cpp)

# Register test runs
enable_testing()
add_test(NAME negDouble_nbr COMMAND cpp06_ex00 -42.01)
add_test(NAME double_nbrChar COMMAND 42.01a)

#add_test(NAME run_with_input2 COMMAND my_app input2.txt)
#add_test(NAME run_with_input3 COMMAND my_app input3.txt)

add_executable(cpp06_ex01
        ex01/Serializer.cpp
        ex01/Serializer.hpp
        ex01/main.cpp)

add_executable(cpp06_ex02
        ex02/Base.cpp
        ex02/Base.hpp
        ex02/A.cpp
        ex02/A.hpp
        ex02/main.cpp
        ex02/B.cpp
        ex02/C.cpp)
