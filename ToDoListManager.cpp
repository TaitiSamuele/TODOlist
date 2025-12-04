//
// Created by samue on 17/11/2025.
//

#include "ToDoListManager.h"

void ToDoListManager::menu() {
    //menu to manage multiple ToDoLists
    char choice;
    do {
        cout<<"\nMenu ToDoListManager:\n";
        cout<<"w: aggiungi nuova lista\n";
        cout<<"e: rimuovi lista per nome file\n";
        cout<<"r: stampa la lista\n";
        cout<<"t: usa lista per nome file\n";
        cout<<"q: esci\n";
        cin>>choice;
        switch (choice) {
            case 'q':
                cout << "uscita...\n";
            break;
            case 'w': {
                //add new list
                string fileName;
                cout << "inserisci il nome del file per la nuova lista: ";
                cin >> fileName;
                addList(fileName);
                //saveListsToFile();
            }
            break;
            case 'e': {
                //remove list by file name
                string fileName;
                cout << "inserisci il nome del file della lista da rimuovere: ";
                cin >> fileName;
                removeListByFileName(fileName);
                //saveListsToFile();
            }
            break;
            case 'r': {
                //print all lists
                for (ToDoList &list: lists) {
                    cout << "Lista da file: " << list.toString() << "\n";
                }
            }
            break;
            case 't': {
                //use list by file name
                string fileName;
                cout << "inserisci il nome del file che vuoi usare: ";
                cin >> fileName;
                for (ToDoList &list: lists) {
                    if (list == fileName) {
                        list.menu();
                    }
                }
            }
            break;
            default:
                cout << "nesssuna scelta valida\n";
        }
        if (choice != 'q') {
            cout << "premi una lettera qualsiasi per continuare... q per uscire\n";
            cin>>choice;
        }
    }while (choice != 'q');
    saveListsToFile();
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
            const char* char_fileName = ("../files/" + fileName).c_str();
            remove(char_fileName);
            return true;
        }
        i++;
    }
    return false;
}

bool ToDoListManager::addList(const string &fileName){
    for (ToDoList &list: lists) {
        if (list == fileName) {
            return false;
        }
    }
    lists.push_back(ToDoList(fileName));
    return true;
}

