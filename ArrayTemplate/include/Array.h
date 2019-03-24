#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Arrays
{
    private:
        int *A;
        int Size;
        int length;
    public:
        Arrays();
        Arrays(int Size);
        void Display();
        void Insert(int index, int value);
        int Delete(int index);
        virtual ~Arrays();

};

#endif // ARRAY_H
