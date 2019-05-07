#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node*prev;
};

class QueueLinkedList
{
    private:
        Node *first;
        Node *last;
    public:
        QueueLinkedList();
        virtual ~QueueLinkedList();
        void AddFirst(int x);
        int RemoveFirst();
        void AddLast(int x);
        int RemoveLast();
        void Display();
};

#endif // QUEUELINKEDLIST_H
