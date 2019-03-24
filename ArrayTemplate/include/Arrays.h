#ifndef ARRAYS_H
#define ARRAYS_H
#include<iostream>
using namespace std;
template<class T>
class Arrays
{
    private:
        T *A;
        int Size;
        int length;
    public:
        Arrays();
        Arrays(int Size);
        void Display();
        void Insert(int index, T value);
        T Delete(int index);
        virtual ~Arrays();
};

#endif // ARRAYS_H
#include "implementation.h"
