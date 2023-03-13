#pragma once
#include <string>

class Node
{
    private:
        //std::string data;
        int data;
        Node *next;

    public:
        Node();
        //Node(std::string data);
        Node(int data);
        //Node(std::string data, Node *next);
        Node(int data, Node *next);

        //std::string getData();
        int getData();
        Node *getNext();

        //void setData(std::string data);
        void setData(int data);
        void setNext(Node *next);
};