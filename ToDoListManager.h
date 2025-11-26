//
// Created by samue on 17/11/2025.
//

#ifndef TODOLISTMANAGER_H
#define TODOLISTMANAGER_H

#include "ToDoList.h"
#include <vector>
#include <string>
using namespace std;

//in questa classe gestirò più liste di ToDoElement, ognuna con un proprio file di salvataggio, i file disponibili vengono gestiti in un file "lists.txt"

class ToDoListManager {
private:
    vector<ToDoList> lists;
    string file = "../lists.txt";
public:
    ToDoListManager(){
        getListsFromFile();
    };
    ~ToDoListManager() = default;

    void menu();
    bool getListsFromFile();
    bool saveListsToFile();
    bool removeListByFileName(const string& fileName);
    bool addList(const string& fileName);
};



#endif //TODOLISTMANAGER_H
