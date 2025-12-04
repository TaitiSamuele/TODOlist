cmake_minimum_required(VERSION 3.28)
project(ToDoTests)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES
        ../ToDoElement.cpp
        ../ToDoList.cpp
        ../ToDoListManager.cpp
)

add_executable(runTests
        test_ToDoElement.cpp
        test_ToDoList.cpp
        test_ToDoManager.cpp
        ${SOURCE_FILES}
)

# --- LINKING (DOPO aver creato l'eseguibile) ---
target_link_libraries(runTests GTest::gtest_main)
target_include_directories(runTests PRIVATE ..)
