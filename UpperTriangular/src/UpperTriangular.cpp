#include "UpperTriangular.h"

UpperTriangular::UpperTriangular(int n)
{
    this->Size = n*(n + 1)/2;
    this->n = n;
    this->A = new int[this->Size];
}

UpperTriangular::~UpperTriangular()
{
    delete []A;
}

int UpperTriangular::Get(int i, int j){
    if(j >= i)
        return this->A[this->n*(i - 1) - ((i - 2)*(i - 1)/2) + (j - i)];
    else
        return 0;
}

void UpperTriangular::Set(int i, int j, int x){
    if(j >= i)
        this->A[this->n*(i - 1) - (i-2)*(i - 1)/2 + (j - i)] = x;
}

void UpperTriangular::Display(){
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            cout << Get( i,  j) <<" ";
        }
        cout << endl;
    }
}
