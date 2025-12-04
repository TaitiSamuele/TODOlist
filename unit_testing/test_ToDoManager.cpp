//
// Created by samue on 02/12/2025.
//
#include "ToDoListManager.h"
#include <gtest/gtest.h>

TEST(ToDoManagerTest, Add_RemoveTest) {
    ToDoListManager manager;
    EXPECT_TRUE(manager.addList("testlist.txt"));
    EXPECT_TRUE(manager.addList("Another_testlist.txt"));
    EXPECT_FALSE(manager.addList("Another_testlist.txt"));

    EXPECT_TRUE(manager.removeListByFileName("testlist.txt"));
    EXPECT_TRUE(manager.removeListByFileName("testlist.txt"));
    EXPECT_FALSE(manager.removeListByFileName("nonexistent.txt"));

}