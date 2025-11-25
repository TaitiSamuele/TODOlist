//
// Created by samue on 17/11/2025.
//

#include "ToDoList.h"
#include <algorithm>
using namespace std;


void ToDoList::menu() {
    char choice = '';
    do {
        switch (choice) {
            case 'a': {
                //add element by user input
                string title, content;
                int priority;
                cout << "inserisci titolo: ";
                cin >> title;
                cout << "inserisci contenuto: ";
                cin >> content;
                cout << "inserisci priorita (1-10): ";
                cin >> priority;
                addElement(title, content, priority);
            }
            break;
            case 's': {
                //remove by title
                string title;
                cout << "inserisci titolo da rimuovere: ";
                cin >> title;
                removeElementByTitle(title);
            }
            case 'd': {
                //sort by priority
                sortByPriority();
            }

            default:
                cout << "nesssuna scelta valida\n";
        }
    } while ('q' != choice);
}

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
    for (ToDoElement &element: elements) {
        file << element.toFileString();
    }
    return true;
}

bool ToDoList::addElement(const ToDoElement &element) {
    elements.push_back(element);
    return true;
}

bool ToDoList::addElement(const string &title, const string &content, int priority) {
    ToDoElement element(title, content, priority);
    elements.push_back(element);
    return true;
}

bool ToDoList::removeElementByTitle(const string &title) {
    for (ToDoElement &element: elements) {
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
    for (ToDoElement &element: elements) {
        if (title == element.getTitle()) {
            element.setCompleted();
        }
    }
    return true;
}

bool ToDoList::removeCompletedElements() {
    int i = 0;
    for (ToDoElement &element: elements) {
        if (element.getCompleted()) {
            elements.erase(elements.begin() + i);
        }
        i++;
    }
    return true;
}

string ToDoList::toFileString() {
    return filePath + "\n";
}

bool ToDoList::operator==(const string &s) const {
    return this->filePath == s;
}

string ToDoList::toString() {
    string s = "";
    for (ToDoElement &element: elements) {
        s += element.toString() + "\n";
    }
    return s;
}
