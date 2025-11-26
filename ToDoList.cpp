//
// Created by samue on 17/11/2025.
//

#include "ToDoList.h"
#include <algorithm>
#include <limits>
using namespace std;


void ToDoList::menu() {
    char choice;
    //clear input buffer
    do {
        //clear terminal and show menu
        cout << "\nMenu ToDoList:\n";
        cout << "a: aggiungi elemento\n";
        cout << "s: rimuovi elemento per titolo\n";
        cout << "d: ordina per priorita\n";
        cout << "f: completa elemento per titolo\n";
        cout << "g: rimuovi elementi completati\n";
        cout << "h: stampa elementi\n";
        cout << "j: salva su file\n";
        cout << "k: carica da file\n";
        cout << "q: esci\n";
        cout << "inserisci scelta: ";
        cin >> choice;
        switch (choice) {
            case 'a': {
                //add element by user input
                string title, content;
                int priority;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "inserisci titolo: ";
                getline(cin,title);
                cout << "inserisci contenuto: ";
                getline(cin,content);
                cout << "inserisci priorita (1 la massima -> 10 la minima (valori < 1 vengono inseriti massimi, > 10 vine inserito il minimo): ";
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
            break;
            case 'd': {
                //sort by priority
                cout<<"ordinamento per priorita...\n";
                sortByPriority();
            }
            break;
            case 'f': {
                //complete by title
                string title;
                cout << "inserisci titolo da completare: ";
                cin >> title;
                completeElementByTitle(title);
            }
            break;
            case 'g': {
                //remove completed elements
                cout<<"rimozione elementi completati...\n";
                removeCompletedElements();
            }
            break;
            case 'h': {
                //print elements
                cout << toString();
            }
            break;
            case 'j': {
                //save to file
                cout<<"salvataggio su file...\n";
                printElementsOnFile();
            }
            break;
            case 'k': {
                //load from file
                cout<<"caricamento da file...\n";
                getElementsOnFile();
            }
            break;
            case 'q':
                cout << "uscita...\n";
            break;
            default:
                cout << "nesssuna scelta valida\n";
        }
        if (choice != 'q') {
            cout << "premi una lettera qualsiasi per continuare... q per uscire\n";
            cin>>choice;
        }
    } while ('q' != choice);
    cout<<"uscita dalla lista...\n";
    cout<<"salvataggio su file...\n";
    printElementsOnFile();
}

bool ToDoList::getElementsOnFile() {
    string line;
    ifstream file("../files/" + filePath);
    while (file >> line) {
        ToDoElement element(line);
        elements.push_back(element);
    }
    return true;
}

bool ToDoList::printElementsOnFile() {
    ofstream file("../files/" + filePath);
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
    string s = filePath + "\n";
    for (ToDoElement &element: elements) {
        s += "\t" + element.toString() + "\n";
    }
    return s;
}
