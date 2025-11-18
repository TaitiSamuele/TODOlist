//
// Created by samue on 17/11/2025.
//

#include "ToDoElement.h"

bool ToDoElement::fill(string message) {
}

string ToDoElement::toString() {
    string s = "";
    s += title + "\n " + content + "\n" + date + "\n Priority: " + to_string(priority) + "\n Completed: " + (completed ? "Yes" : "No") + "\n";
    return s;
}

string ToDoElement::toFileString() {
    string s = "";
    s += title + ";" + content + ";" + date + ";" + to_string(priority) + ";" + (completed ? "1" : "0") + "|";
    return s;
}
