#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include<iostream>
using namespace std;

class CircularQueue
{

    private:
        int fr;
        int r;
        int *Q;
        int Size;
    public:
        CircularQueue();
        CircularQueue(int Size);
        void Enqueue(int x);
        int Dequeue();
        void Display();
        virtual ~CircularQueue();
};

#endif // CIRCULARQUEUE_H
