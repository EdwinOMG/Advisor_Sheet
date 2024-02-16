cmake_minimum_required(VERSION 3.27)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)


add_executable(untitled1 main.cpp
        Data_Calls.cpp
        sqlite3.c
)

target_include_directories(untitled1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})