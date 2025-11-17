cmake_minimum_required(VERSION 3.28)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        List.cpp
        List.h
        ToDoListManager.cpp
        ToDoListManager.h)
