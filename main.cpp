#include <iostream>

#include "ToDoList.h"
using namespace std;


int main() {
    ToDoList list = ToDoList("todo.txt");
    list.getElementsOnFile();

    ToDoElement element = ToDoElement("sleep", "get at least 8 hours of sleep", 5);
    list.addElement(element);
    list.addElement("exercise", "go for a 30-minute run", 3);
    list.addElement("whatch_movie", "watch a new movie on streaming platform", 7);

    cout << list.toString();
    list.printElementsOnFile();
}