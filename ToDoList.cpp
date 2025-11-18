//
// Created by samue on 17/11/2025.
//

#include "ToDoList.h"
#include <algorithm>
using namespace std;

bool ToDoList::getElementsOnFile() {
    string line;
    ifstream file(filePath);
    while (file >> line) {
        ToDoElement element(line);
        elements.push_back(element);
    }
    return true;
}

bool ToDoList::printElementsOnFile() {
    ofstream file(filePath);
    for (ToDoElement& element : elements) {
        file << element.toFileString();
    }
    return true;
}

bool ToDoList::addElement(const ToDoElement &element) {
    return true;
}

bool ToDoList::removeElementByTitle(const string &title) {
    for (ToDoElement& element: elements) {
        if (title == element.getTitle()) {
            elements.erase(elements.begin());
        }
    }
    return true;
}

bool ToDoList::sortByPriority() {
    sort(elements.begin(), elements.end());
    return true;
}

bool ToDoList::completeElementByTitle(const string &title) {
    for (ToDoElement& element: elements) {
        if (title == element.getTitle()) {
            element.setCompleted();
        }
    }
    return true;
}

bool ToDoList::removeCompletedElements() {
    int i = 0;
    for (ToDoElement& element: elements) {
        if (element.getCompleted()) {
            elements.erase(elements.begin() + i);
        }
        i++;
    }
    return true;
}

string ToDoList::toString() {
    string s = "";
    for (ToDoElement& element : elements) {
        s += element.toString() + "\n";
    }
    return s;
}
