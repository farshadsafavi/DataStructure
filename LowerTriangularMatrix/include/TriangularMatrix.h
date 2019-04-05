#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H
#include<iostream>
using namespace std;

class TriangularMatrix
{
    private:
        int *A;
        int Size;
        int n;
    public:
        TriangularMatrix(int m);
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        void Set2(int i, int j, int x);
        int Get2(int i, int j);
        void Display2();
        int GetDimension(){ return n;};
        virtual ~TriangularMatrix();


};

#endif // TRIANGULARMATRIX_H
