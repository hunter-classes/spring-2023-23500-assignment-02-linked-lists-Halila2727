/*
    Halil Akca
    CSCI 235
    Assignment 2
*/

#include <iostream>
#include "Node.h"
#include "List.h"
#include "OList.h"

int main(int argc, char *argv[])
{
    /* LIST STUFF IS COMMENTED OUT

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

    */

    /*OLISTS*/

    OList * l1 = new OList();
   
    l1->insert(4);
    l1->insert(18);
    l1->insert(45);
    l1->insert(3);
    l1->insert(7);
    l1->insert(1243);
    l1->insert(333);
    l1->insert(-2344);
    l1->insert(13);


    std::cout << "Current OList: " << l1->toString() << "\n\n";
    std::cout << "Contains number 3: " << l1->contains(3) << "\n";
    std::cout << "Contains number 30: " << l1->contains(30) << "\n";
    std::cout << "Number at index 4: " << l1->get(4) << "\n";
    
    l1->remove(4);
    std::cout << "Remove number at index 4: done" << "\n\n";

    std::cout << "Updated OList: " << l1->toString() << "\n\n";
  

    l1->reverse();
    std::cout << "Reversed OList: " << l1->toString() << "\n\n";
    delete l1;

    std::cout << "\n";
    return 0;
}