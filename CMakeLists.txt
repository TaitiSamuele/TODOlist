cmake_minimum_required(VERSION 3.28)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        ToDoList.cpp
        ToDoList.h
        ToDoListManager.cpp
        ToDoListManager.h
        ToDoElement.cpp
        ToDoElement.h
        unit_testing/test_ToDOElement.cpp
        unit_testing/test_ToDoList.cpp
        unit_testing/test_ToDoManager.cpp)

#enable_testing()
#add_subdirectory(unit_testing)