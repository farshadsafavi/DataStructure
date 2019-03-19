#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Array
{
    private:
        int *A;
        int arraySize;
        int length;
    public:
        Array();
        Array(int arraySize);
        void ArrayInfo();
        void Append(int x);
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        virtual ~Array();


};

#endif // ARRAY_H
