#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue
{
    private:
        Node *f;
        Node *r;
    public:
        Queue();
        void Enqueue(int x);
        int Dequeue();
        void Display();
        virtual ~Queue();
};

#endif // QUEUE_H
