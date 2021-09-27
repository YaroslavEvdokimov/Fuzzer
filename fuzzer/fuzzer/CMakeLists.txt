cmake_minimum_required(VERSION 3.5)

project(Fuzzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Fuzzer main.cpp Create_Log_File.cpp Create_Log_File.h Fuzzer_start.cpp Fuzzer_start.h Generation_start.cpp Generation_start.h)
