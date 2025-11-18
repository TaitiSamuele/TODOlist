//
// Created by samue on 17/11/2025.
//

#ifndef LIST_H
#define LIST_H

#include "ToDoElement.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class ToDoList {
private:
    vector<ToDoElement> elements;
    string filePath;
public:
    explicit ToDoList(const string &file_path): filePath(file_path) {

    }
    ~ToDoList() = default;

    bool getElementsOnFile();
    bool printElementsOnFile();



    string toString();



};


#endif //LIST_H
