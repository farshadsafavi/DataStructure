#ifndef TOEPLITSMATRIX_H
#define TOEPLITSMATRIX_H
#include<iostream>
using namespace std;

class ToeplitsMatrix
{
    private:
        int *A;
        int n;
        int Size;
    public:
        ToeplitsMatrix(int n);
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        void Create();
        virtual ~ToeplitsMatrix();


};

#endif // TOEPLITSMATRIX_H
