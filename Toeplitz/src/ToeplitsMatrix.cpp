#include "ToeplitsMatrix.h"

ToeplitsMatrix::ToeplitsMatrix(int n)
{
    this->Size = 2*n - 1;
    this->A = new int[this->Size];
    this->n = n;

}

ToeplitsMatrix::~ToeplitsMatrix()
{
    delete []A;
}

void ToeplitsMatrix::Set(int i, int j, int x){
    if(i <= j)
        this->A[j - i] = x;
    else
        this->A[n - 1 + i - j] = x;

}

int ToeplitsMatrix::Get(int i, int j){
    if(i <= j)
        return this->A[j - i];
    else
        return this->A[n - 1 + i - j];
}

void ToeplitsMatrix::Display(){
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            cout <<Get(i, j) <<" ";
        }
        cout <<endl;
    }
}

void ToeplitsMatrix::Create(){
    int x = 0;
    cout <<"Enter elements of toelipts:\n";
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            cin >> x;
            this->Set(i, j, x);
        }
    }
}
