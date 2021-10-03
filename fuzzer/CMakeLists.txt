cmake_minimum_required(VERSION 3.5)

project(Fuzzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Fuzzer main.cpp CreateLogFile.cpp CreateLogFile.h FuzzerStart.cpp FuzzerStart.h GenerationStart.cpp GenerationStart.h)
