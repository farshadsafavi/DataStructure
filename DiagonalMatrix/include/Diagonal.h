#ifndef DIAGONAL_H
#define DIAGONAL_H
#include<iostream>
using namespace std;

class Diagonal
{
    private:
        int n;
        int *A;
    public:
        Diagonal();
        Diagonal(int n);
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        virtual ~Diagonal();


};

#endif // DIAGONAL_H
