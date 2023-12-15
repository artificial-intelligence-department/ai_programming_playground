cmake_minimum_required(VERSION 3.26)
project(Class_practice_work)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(books)

add_executable(Class_practice_work
        books/book.cpp
        books/book.h
        main.cpp
)
