#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload);


    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}


int LinkedList::getFront()
{
    return this->head->getPayload();
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}
void LinkedList::addEnd(int payload)
{
   Node* currentNode = this->head;
   for(int i = 0; i < this->count; i++)
    {
        if(currentNode->getNextNode() == NULL)
        {
            Node* m = new Node(payload);
            currentNode->setNextNode(m);
            this->tail = m;
            this->count++;
        }
        else
        {
            currentNode = currentNode->getNextNode();
        }
        
    }

}
int LinkedList::getEnd()
{
    return this->tail->getPayload();
}
int LinkedList::removeEnd()
{
    Node* returnNode = this->tail;
    int value = returnNode->getPayload();
    delete returnNode;
    this->count--;
    return value;
}
