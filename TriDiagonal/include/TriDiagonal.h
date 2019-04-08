#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H
#include<iostream>


class TriDiagonal
{
    private:
        int *A;
        int Size;
        int n;
    public:
        TriDiagonal(int n);
        void Set(int i, int j, int x);
        void Create();
        int Get(int i, int j);
        void Display();
        virtual ~TriDiagonal();

};

#endif // TRIDIAGONAL_H
