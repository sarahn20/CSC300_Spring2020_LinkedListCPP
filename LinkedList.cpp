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

Node* LinkedList::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;
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

void LinkedList::displayPointers()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode << "\n";
        currNode = currNode->getNextNode();
    }
}

void LinkedList::sort()
{
    Node* lastPoint = this->head;
    Node* currPoint = lastPoint->getNextNode();
    Node* tempPoint = currPoint->getNextNode();
    Node* followTheLast = lastPoint;
    while(isSorted() == false)
    {
        for(int j = 0; j<=this->count; j++)
        {
            if(this->head->getPayload()>currPoint->getPayload())
            {
                currPoint->setNextNode(lastPoint);
                lastPoint->setNextNode(tempPoint);
                this->head = currPoint;
                //resets pointers
                lastPoint = this->head;
                currPoint = lastPoint->getNextNode();
                tempPoint = currPoint->getNextNode();
            }
            //The following code will be in a loop

            for(int i = 0; i<=this->count-j; i++)
            {
                if(currPoint->getPayload() > tempPoint->getPayload())
                {
                    //performs swap
                    lastPoint->setNextNode(tempPoint);
                    currPoint->setNextNode(tempPoint->getNextNode());
                    tempPoint->setNextNode(currPoint);
            
                    //resets pointers
                    lastPoint = followTheLast;
                    currPoint = lastPoint->getNextNode();
                    tempPoint = currPoint->getNextNode();
                }
                //Progress pointers
                if(tempPoint->getNextNode()!=0)
                {
                    lastPoint = lastPoint->getNextNode();
                    currPoint = currPoint->getNextNode();
                    tempPoint = tempPoint->getNextNode();
                    followTheLast = lastPoint;
                }   
            } 
            lastPoint = this->head;
            currPoint = lastPoint->getNextNode();
            tempPoint = currPoint->getNextNode(); 
        }
    }
}

bool LinkedList::isSorted()
{
    Node* first = this->head->getNextNode();
    Node* second = this->head;
    for(int i = 0; i<this->count-1; i++)
    {
       if(first->getPayload()>second->getPayload())
       {
           first = first->getNextNode();
           second = second->getNextNode();
       }
       else if (first->getPayload()<second->getPayload())
       {
           return false;
       }
    }
    return true;
}

/*
void LinkedList::sort()
{
    for(int i = 0; i < this->count-1; i++)
    {
        if(this->getIndex(i) > this->getIndex(i+1))
        {
            this->addAtIndex(i, this->removeIndex(i+1));
            if(i > 0)
            {
                i = i -2;
            }
        }
    }
}
*/

void LinkedList::addEnd(int payload)
{
   if(!this->head)
   {
       this->addFront(payload);
   }
   else
   {
       //we have at least one thing in our list
       //traverse to end of list and connect new node

       Node* n = new Node(payload);
       Node* currNode = this->runToEndOfList();
       //currNode now points to the end of our list (ie the last Node)
       currNode->setNextNode(n);
       this->count++;
   }
}
int LinkedList::getEnd()
{
    Node* currNode = this->runToEndOfList();
    //currNode points to the end of the list
    return currNode->getPayload();
}
int LinkedList::removeEnd()
{
    //we are assuming the list has at least one element in it for now
    //is this a list with a single element in it?
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        //we have at least two elements in our list
        Node* theLastGuy = this->runToEndOfList();
        Node* theGuyBeforeTheLastGuy = this->head;
        while(theGuyBeforeTheLastGuy->getNextNode() != theLastGuy)
        {
            theGuyBeforeTheLastGuy = theGuyBeforeTheLastGuy->getNextNode();
        }
        //theGuyBeforeTheLastGuy now points to the Node right before theLastGuy
        theGuyBeforeTheLastGuy->setNextNode(0);
        int valueToReturn = theLastGuy->getPayload();
        delete theLastGuy;
        this->count--;
        return valueToReturn;
    }
    
}

int LinkedList::getIndex(int index)
{
    if(index == 0)
    {
        return this->getFront();
    }
    else if(index == this->count-1)
    {
        return this->getEnd();
    }
    else
    {
        Node* currNode = this->head; //gives us a second pointer to the front of the list
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();

    }
}

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else if(index == this->count)
    {
        this->addEnd(payload);
    }
    else
    {
        //we are placing somewhere in the middle
        Node* n = new Node(payload);
        Node* currNode = this->head;
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode -> getNextNode();
        }
        //currNode points ot the node right before where N should be inserted
        n->setNextNode(currNode->getNextNode());
        currNode->setNextNode(n);
        this->count++;
    }
}

int LinkedList::removeIndex(int index)
{
   if(index == 0)
   {
       return this->removeFront();
   }
   else if(index == this->count-1)
   {
       return this->removeEnd();
   }
   else
   {
       Node* currNode = this->head;
       for(int i = 0; i < this->count; i++)
       {
           currNode = currNode->getNextNode();
       }
       Node* guy2Remove = currNode->getNextNode();
       currNode->setNextNode(guy2Remove->getNextNode());
       guy2Remove->setNextNode(0); //sets his next node to null
       int val2Return = guy2Remove->getPayload();
       delete guy2Remove; //hasn't erased the memory, just unmarks the memory location
       this->count--;
       return val2Return; //return ends the method

   }
}
