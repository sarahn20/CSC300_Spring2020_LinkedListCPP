#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}


void LinkedList::addFront(int payload)
{
    this->payload = payload;
    Node* n = new Node(payload);
    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        n.setNextNode(this->head)
        this->head = n;
    }
    this->count++;
}
