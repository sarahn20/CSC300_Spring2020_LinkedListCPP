#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

//needs a semicolon because read in as a statement by the compiler

class LinkedList
{
private: 
    Node* head;
    int count;
    Node* runToEndOfList();

public: 
    LinkedList();
    void addFront(int payload);
    int getFront();
    int removeFront();
    void addEnd(int payload);
    int getEnd();
    int removeEnd();
    void addAtIndex(int index, int payload);
    int getIndex(int index);
    int removeIndex(int index);
    void display();
    void displayPointers();
    void sort(); //re-arranges the linked list such that it is in ascedning numerical order
    bool isSorted();
};
#endif /* LinkedList_hpp */