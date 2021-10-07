cmake_minimum_required(VERSION 3.5)

project(Converter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Converter Converter.cpp ConverterStart.cpp  ConverterStart.h)
