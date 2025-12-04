//
// Created by samue on 02/12/2025.
//
#include <gtest/gtest.h>
#include "ToDoElement.h"
#include <string>
using namespace std;

TEST(ToDoElementTest, ConstructorTest_GetterTest) {
//controllo il costruttore e i getter
    ToDoElement element("Test Title", "Test Content", 5);
    EXPECT_EQ(element.getTitle(), "Test Title");
    EXPECT_EQ(element.getContent(), "Test Content");
    EXPECT_EQ(element.getPriority(), 5);
    EXPECT_FALSE(element.getCompleted());

//controllo fill
    string message = "Test_Title|Test_Content|01/01/2024, 12:00|3|0";
    ToDoElement element2(message);
    EXPECT_EQ(element2.getTitle(), "Test Title");
    EXPECT_EQ(element2.getContent(), "Test Content");
    EXPECT_EQ(element2.getPriority(), 3);
    EXPECT_EQ(element2.getDate(), "01/01/2024, 12:00");
    EXPECT_FALSE(element2.getCompleted());
}
TEST(ToDoElementTest, SetCompletedTest) {
//controllo setCompleted
    ToDoElement element("Test Title", "Test Content", 5);
    element.setCompleted();
    EXPECT_TRUE(element.getCompleted());
}
TEST(ToDoElementTest, ToFileStringTest) {
//controllo toFileString
    ToDoElement element("Test Title", "Test Content", 5);
    string expected = "Test_Title|Test_Content|";
    string date = element.getDate();
    replace(date.begin(), date.end(), ' ', '_');
    expected += date + "|5|0\n";
    EXPECT_EQ(element.toFileString(), expected);
}
