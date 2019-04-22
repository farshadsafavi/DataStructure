#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<Node.h>
#include<iostream>
using namespace std;

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList();
        void Display();
        void Insert(int i, int value);
        int Count();
        void Reverse();
        void ReverseRec();
        void ReverseRec(Node *p, Node *c);
        virtual ~LinkedList();


};

#endif // LINKEDLIST_H
