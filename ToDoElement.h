//
// Created by samue on 17/11/2025.
//

#ifndef TODOELEMENT_H
#define TODOELEMENT_H

using namespace std;
#include <string>

class ToDoElement {
private:
   int id;
   string title;
   string content;
   string date;
   int priority;
   bool completed;

public:
   ToDoElement() = default;
   ~ToDoElement() = default;

   bool fill(string message); //ogni attributo e' separato da ';', la virgola potrebbe essere usata nel content
   string toString();//delego la froamttazione della stringa agli elementi

};



#endif //TODOELEMENT_H
