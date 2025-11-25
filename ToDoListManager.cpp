//
// Created by samue on 17/11/2025.
//

#include "ToDoListManager.h"

bool ToDoListManager::menu() {

}

bool ToDoListManager::getListsFromFile() {
    string line;
    ifstream file(this->file);
    while (file >> line) {
        lists.push_back(ToDoList(line));
    }
    return true;
}

bool ToDoListManager::saveListsToFile() {
    ofstream file(this->file);
    for (ToDoList list: lists) {
        file << list.toFileString();
    }
    return true;
}

bool ToDoListManager::removeListByFileName(const string &fileName) {
    int i = 0;
    for (ToDoList &list: lists) {
        if (list == fileName) {
            lists.erase(lists.begin() + i);
        }
        i++;
    }
    return true;
}

bool ToDoListManager::addList(const string &fileName){
    lists.push_back(ToDoList(fileName));
}

