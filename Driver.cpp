#include "LinkedList.hpp"
#include <iostream>
int main()
{
    LinkedList* ll = new LinkedList();
    ll->addFront(1);
    ll->addFront(2);
    ll->addEnd(3);
    std::cout << ll->removeEnd() << "\n";
    ll->display();
    delete ll;
}