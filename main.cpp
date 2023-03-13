/*
    Halil Akca
    CSCI 235
    Assignment 2
*/

#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[])
{
    List *l = new List();
    
    std::cout << l->toString() << " " << l->length() << "\n";
    
    l->insert(0,"a");
    
    std::cout << l->toString() << " " << l->length() << "\n";
    
    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");
    
    try {
        l->insert(10,"x");
    } catch (std::exception e){
        std::cout << "Insert x didn't work\n";
    }
    
    std::cout << l->toString() << "\n";
    l->insert(3,"3");
    std::cout << l->toString() << "\n";
    l->insert(4,"4");
    std::cout << l->toString() << " " << l->length() << "\n";

    std::cout << "\n---\n" << l->contains("a") << "\n";
    std::cout << l->contains("7") << "\n";
    std::cout << l->contains("4") << "\n";
    std::cout << l->contains("1") << "\n";
    std::cout << l->contains("3") << "\n";
    std::cout << l->contains("b") << "\n";
    std::cout << l->contains("e") << "\n";

    std::cout << "\n---\n" << l->toString();
    
    l->remove(1);
    l->remove(1);

    std::cout << "\n\n" << l->toString() << "\n";

    std::cout << "\n" << l->find("4") << "\n";

    return 0;
}