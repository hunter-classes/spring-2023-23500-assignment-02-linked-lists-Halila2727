#pragma once
#include <iostream>
#include "Node.h"

class List
{
    private:
    Node *head;
    
    public:
    
    List();
    
    //void insert(std::string data);
    //void insert(int loc, std::string data);
    void insert(int data);
    void insert(int loc, int data);
    int length();

    std::string toString();
    
    ~List();
    
    void remove(int loc);
    
    //std::string get(int loc);
    int get(int loc);
    
    //bool contains(std::string item);
    bool contains(int item);
    
    //std::string find(std::string data);
};
