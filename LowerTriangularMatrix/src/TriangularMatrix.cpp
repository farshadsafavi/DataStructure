#include "TriangularMatrix.h"

TriangularMatrix::TriangularMatrix(int m)
{
    this->Size = m*(m+1)/2;
    this->n = m;
    this->A = new int[this->Size];
}

TriangularMatrix::~TriangularMatrix()
{
    delete []A;
}

void TriangularMatrix::Set(int i, int j, int x){
    if(i >= j)
        this->A[(i*(i - 1)/2) + (j - 1)] = x;
}

int TriangularMatrix::Get(int i, int j){
    if(i >= j)
        return this->A[(i*(i - 1)/2) + (j - 1)];
    else
        return 0;
}


void TriangularMatrix::Display(){
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            cout <<Get(i, j) << " ";
        }
        cout <<endl;
    }
}

void TriangularMatrix::Set2(int i, int j, int x){
    if(i >= j)
        this->A[n*(j - 1) - ((j - 2)*(j -1)/2) + (i - j)] = x;
}

int TriangularMatrix::Get2(int i, int j){
    if(i >= j)
        return this->A[n*(j - 1) - ((j - 2)*(j -1)/2) + (i - j)];
    else
        return 0;
}


void TriangularMatrix::Display2(){
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            cout <<Get(i, j) << " ";
        }
        cout <<endl;
    }
}

