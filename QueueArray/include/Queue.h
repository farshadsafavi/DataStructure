#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

template<class T>
class Queue
{
    private:
        int fr;
        int rear;
        int Size;
        T *Q;
    public:
        Queue();
        Queue(int Size);
        void Enqueue(T x);
        T Dequeue();
        bool isEmpty();
        bool isFull();
        void Display();
        virtual ~Queue();
};

#endif // QUEUE_H
#include "implementation.h"
