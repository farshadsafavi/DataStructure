#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

template<class T>
struct Node{
    T data;
    Node *next;
};

template<class T>
class Stack
{
    private:
        Node<T> *top;
    public:
        Stack();
        virtual ~Stack();
        void Push(int x);
        T Pop();
        bool isFull();
        bool isEmpty();
        T Peek(int pos);
        void Display();
        T StackTop();
    protected:


};

#endif // STACK_H
#include "implementation.h"
