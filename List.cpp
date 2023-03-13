#include <iostream>
#include "Node.h"
#include "List.h"

List::List()
{
    head = nullptr;
}

void List::insert(std::string data)
{
    Node *tmp = new Node(data);
    tmp->setNext(head);
    head = tmp;
}

void List::insert(int loc, std::string data)
{
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr; // one behind
  
    while(loc>0 && walker != nullptr)
    {
        loc=loc-1;

        trailer=walker;
        walker = walker->getNext();
    
    }


    if (loc > 0)
    {
        throw std::out_of_range("Our insert is out of range");
    }

    Node *newNode = new Node(data);

    if (trailer == nullptr)
    {
        newNode->setNext(head);
        head = newNode;
    } 
    else 
    {
        // do the regular case 
        newNode->setNext(walker);
        trailer->setNext(newNode);
    }
}

int List::length()
{
    int count = 0;
    Node *walker = head;
    while (walker != nullptr)
    {
        count++;
        walker = walker->getNext();
    }
    return count;
}

std::string List::toString()
{
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr)
    {
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

List::~List()
{
    delete[] head;
}

void List::remove(int loc)
{
    Node *walker;
    Node *traileer;
    
    walker = this -> head;
    traileer = nullptr;
    
    for(int i = 0; i < loc; i++)
    {
        traileer = walker;
        walker = walker -> getNext();
    }
    traileer -> setNext(walker ->getNext());
    walker ->setNext(nullptr);
    walker->setData("");
}

/*
std::string List::get(int loc)
{

}*/

bool List::contains(std::string item)
{
    Node *n = this->head;

    while(n != nullptr)
    {
        if (n->getData() == item)
        {
            return true;
        }
        n = n->getNext();
    }
    
    return false;
}

std::string List::find(std::string data)
{
    Node *walker = head;
    
    while(walker->getData() != data && walker != nullptr)
    {
        walker = walker->getNext();
    }

    if(walker == nullptr)
    {
        return nullptr;
    }
    else
    {
        return walker->getData();
    }
}