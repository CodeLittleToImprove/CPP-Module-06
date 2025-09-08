cmake_minimum_required(VERSION 3.30)
project(cpp06)

set(CMAKE_CXX_STANDARD 98)


add_executable(cpp06_ex00
        ex00/ScalarConverter.cpp
        ex00/ScalarConverter.hpp
        ex00/main.cpp)

add_executable(cpp06_ex01
        ex01/Serializer.cpp
        ex01/Serializer.hpp
        ex01/main.cpp)

add_executable(cpp06_ex02
        ex02/Base.cpp
        ex02/Base.hpp
        ex02/A.cpp
        ex02/A.hpp
        ex02/main.cpp)
