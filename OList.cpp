#include <iostream>

#include "OList.h"
#include "Node.h"
//#include "List.h"

OList::OList()
{
    head = nullptr;
}

OList::~OList()
{
    std::cerr << "Calling the destructor\n";
    Node *walker = head;
    Node *trailer = nullptr;
    
    while (walker != nullptr)
    {
        trailer=  walker;
        walker = walker->getNext();
        std::cerr << "Deleting " << trailer->getData() << ", ";
        delete trailer;
    }
    
    std::cerr << "\n";
}

void OList::insert(int data)
{
    Node *walker = head;
    Node *trailer = nullptr;
    Node *tmp = new Node(data);

    while (walker != nullptr && data > walker->getData())
    {
        trailer = walker;
        walker = walker->getNext();
    }

    if (trailer == nullptr)
    {
        tmp->setNext(head);
        head = tmp;
    } 
    else 
    {
        trailer->setNext(tmp);
        tmp->setNext(walker);
    }
}


std::string OList::toString()
{
    Node *tmp = this->head;
    std::string result = "";
    
    while (tmp != nullptr)
    {
        result = result + std::to_string(tmp->getData());
        result = result + " --> ";
        tmp = tmp->getNext();
    }
  
    result = result + "nullptr";
    return result;
}


bool OList::contains(int data)
{
    Node *walker = head;

    while(walker != nullptr)
    {
        if(walker->getData() == data)
        {
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}


int OList::get(int loc)
{
    Node * walker = head;

    while (walker && loc > 0)
    {
        walker = walker -> getNext();
        loc--;
    }

    if (walker != nullptr)
    {
        return walker->getData();
    }
    
    return -1; //couldn't get it
}

void OList::remove(int index)
{
    Node * walker = head;
    Node * trailer = nullptr;

    while (index > 0 && walker != nullptr)
    {
        trailer = walker;
        walker = walker->getNext();
        index--;
    }

    if (walker == nullptr)
    {
        throw std::out_of_range("Tried to remove out of range");
    }

    if (trailer == nullptr)
    {
        head = walker->getNext();
        delete walker;
    }
    else
    {
        trailer->setNext(walker->getNext());
        delete walker;
    }
}

void OList::reverse()
{
    if(head == nullptr)
    {
        return;
    }

    Node * walker = head;
    Node * trailer = nullptr;
    Node * tmp = nullptr;
    
    while(walker)
    {
        tmp = walker->getNext();
        walker->setNext(trailer);
        trailer = walker;
        walker = tmp;
    }
  
    head = trailer;
}