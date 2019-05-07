#ifndef QUEUE_H
#define QUEUE_H
#include<stack>
#include<iostream>
using namespace std;

class Queue
{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        Queue();
        void Enqueue(int x);
        int Dequeue();
        void Display();
        bool isEmpty();
        int Size();
        virtual ~Queue();
};

#endif // QUEUE_H
