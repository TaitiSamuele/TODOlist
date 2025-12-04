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
TEST(ToDoListTest, Add_Complete_RemoveTest) {
    ToDoList list("testfile.txt");
    EXPECT_TRUE(list.addElement("Test Title", "Test Content", 1));
    EXPECT_FALSE(list.addElement("Test Title", "abc", 5));
    ToDoElement element("Test Title", "dce", 5);
    EXPECT_FALSE(list.addElement(element));
    list.addElement("Another Test Title", "Test Content", 3);
    list.addElement("AnotherAnother Test Title", "Test Content", 10);

    EXPECT_TRUE(list.removeElementByTitle("AnotherAnother Test Title"));
    EXPECT_FALSE(list.removeElementByTitle("Nonexistent Title"));

    EXPECT_TRUE(list.completeElementByTitle("Test Title"));
    EXPECT_FALSE(list.completeElementByTitle("Test Title"));
    EXPECT_FALSE(list.completeElementByTitle("Nonexistent Title"));
}

