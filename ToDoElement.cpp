//
// Created by samue on 17/11/2025.
//

#include "ToDoElement.h"

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::vector;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

bool ToDoElement::fill(string message) {
    replace(message.begin(), message.end(), '_', ' ');
    vector<string> word = split(message, ';');
    if (word.size() != 5) {
        return false;
    }
    title = word[0];
    content = word[1];
    date = word[2];
    priority = stoi(word[3]);
    completed = (word[4] == "1" ? true : false);
    return true;
}

string ToDoElement::toString() {
    string s = "";
    s += title + "\n " + content + "\n" + date + "\n Priority: " + to_string(priority) + "\n Completed: " + (completed ? "Yes" : "No") + "\n";
    return s;
}

string ToDoElement::toFileString() {
    string s = "";
    s += title + ";" + content + ";" + date + ";" + to_string(priority) + ";" + (completed ? "1" : "0") + "\n";
    replace(s.begin(), s.end(), ' ', '_');
    return s;
}

