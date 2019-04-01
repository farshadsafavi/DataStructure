#include "Diagonal.h"
Diagonal::Diagonal()
{
    this->n = 2;
    this->A = new int[this->n];
}

Diagonal::Diagonal(int n)
{
    this->n = n;
    this->A = new int[n];
}

void Diagonal::Set(int i, int j, int x){
    if(i == j)
        this->A[i - 1] = x;
}

int Diagonal::Get(int i, int j){
    if(i == j)
        return this->A[i - 1];
    else
        return 0;
}

void Diagonal::Display(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                cout << this->A[i] << " ";
            else
                cout << "0 ";
        }
        cout <<endl;
    }
    cout << endl;
}

Diagonal::~Diagonal()
{
    delete []A;
}
