    cmake_minimum_required(VERSION 3.26)
project(Class_practice_work)

set(CMAKE_CXX_STANDARD 17)

add_executable(Class_practice_work main.cpp
        helpers/string_helper.cpp
        helpers/string_helper.h
        epic2.h
        epic2.cpp
)
