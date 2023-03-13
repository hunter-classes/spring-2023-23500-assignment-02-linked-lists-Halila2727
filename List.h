#pragma once
#include <iostream>
#include "Node.h"

class List
{
    private:
    Node *head;
    
    public:
    
    List();
    
    void insert(std::string data);
    void insert(int loc, std::string data);
    int length();

    std::string toString();
    
    ~List();
    
    void remove(int loc);
    std::string get(int loc);
    bool contains(std::string item);
    std::string find(std::string data);
};
