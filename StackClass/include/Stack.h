#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template<class T>
class Stack
{
    private:
        int top;
        int Size;
        T *s;
    public:
        Stack(){Size=10;top=-1;s=new T[Size];}
        Stack(int Size);
        void Push(T x);
        T Pop();
        bool isEmpty();
        bool isFull();
        void Display();
        T Peek(int pos);
        T StackTop();
        virtual ~Stack();

    protected:


};

#endif // STACK_H
#include "implementation.h"
