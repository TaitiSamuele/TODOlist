//
// Created by samue on 17/11/2025.
//

#include "ToDoList.h"
using namespace std;

bool ToDoList::getElementsOnFile() {
}

bool ToDoList::printElementsOnFile() {
}

string ToDoList::toString() {
    for (ToDoElement& element : elements) {
        cout << element.toString() << endl;
    }
}
