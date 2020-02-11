#include "Node.hpp"
#include <stdlib.h>

//implementing the things defined in the header file

Node::Node(int payload)
{
    this->payload = payload;
}
void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}