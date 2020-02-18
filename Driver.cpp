#include "LinkedList.hpp"
#include <iostream>
int main()
{
    LinkedList* ll = new LinkedList();
    ll->addFront(1);
    ll->addFront(2);
    ll->addEnd(3);
    ll->display();
    //ll->display();
    //int indy = ll->getIndex(1);
    //std::cout << indy << "\n";
    int milo = ll->removeIndex(1);
    std::cout << milo << "\n";
    ll->display();
    delete ll;
}