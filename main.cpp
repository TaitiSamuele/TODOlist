#include <iostream>

#include "ToDoList.h"
using namespace std;


int main() {
    ToDoList list = ToDoList("../files/todo.txt");
    list.getElementsOnFile();

    list.addElement("comprare banane", "andare al supermercato e comprare delle banane", 5);
    //list.completeElementByTitle("comprare banane");
    list.removeCompletedElements();

    cout << list.toString();
    list.printElementsOnFile();
}