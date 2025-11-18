//
// Created by samue on 17/11/2025.
//

#ifndef TODOELEMENT_H
#define TODOELEMENT_H

using namespace std;
#include <string>
#include <ctime>

class ToDoElement {
private:
   string title;
   string content;
   string date;
   int priority;
   bool completed;

public:
   explicit ToDoElement(string message){ fill(message);}
   ToDoElement(const string &title, const string &content, int priority)
      : title(title),
        content(content),
        completed(false) {
      if (priority > 10) {
         this->priority = 10;
      } else if (priority < 1) {
         this->priority = 1;
      } else {
         this->priority = priority;
      }
      time_t now = time(nullptr);
      tm* local = localtime(&now);

      char buffer[20];
      strftime(buffer, sizeof(buffer), "%d/%m/%Y, %H:%M", local);
      date = buffer;
   }
   ~ToDoElement() = default;

   bool fill(string message); //ogni attributo e' separato da ';', la virgola potrebbe essere usata nel content
   string toString();//delego la froamttazione della stringa agli elementi
   string toFileString();//delego la formattazione della stringa agli elementi, "|" separa i vari elementi, ";" separa gli attributi

   string getTitle() {
      return title;
   }
   int getPriority() {
      return priority;
   }
   bool getCompleted() {
      return completed;
   }
   void setCompleted() {
      completed = true;
   }

   int operator< (const ToDoElement& other) const {
      return this->priority < other.priority;
   }

};



#endif //TODOELEMENT_H
