#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include<iostream>
using namespace std;

class QueueArray
{
    private:
        int f;
        int r;
        int *Q;
        int Size;
    public:
        QueueArray();
        QueueArray(int Size);
        void AddFirst(int x);
        int RemoveFirst();
        void AddLast(int x);
        int RemoveLast();
        void Display();
        virtual ~QueueArray();
};

#endif // QUEUEARRAY_H
