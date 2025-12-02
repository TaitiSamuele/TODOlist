//
// Created by samue on 02/12/2025.
//
#include <gtest/gtest.h>
#include "ToDoList.h"
#include <string>
using namespace std;

TEST(ToDoListTest, ConstructorTest) {
//controllo il costruttore
    ToDoList list("testfile.txt");
    EXPECT_EQ(list.getFileName(), "testfile.txt");
}