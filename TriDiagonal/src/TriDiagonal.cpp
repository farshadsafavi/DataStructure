#include "TriDiagonal.h"

TriDiagonal::TriDiagonal(int n)
{
    this->A = new int[3*n - 2];
    this->Size = 3*n - 2;
    this->n = n;
}

TriDiagonal::~TriDiagonal()
{
    delete []A;
}

void TriDiagonal::Set(int i, int j, int x){
    if(i == j)
        this->A[n + i - 1] = x;
    if(i - j == 1)
        this->A[j - 1] = x;
    if(j - i == 1)
        this->A[2*n - 1 + i - 1] = x;
}

int TriDiagonal::Get(int i, int j){
    if(i == j)
        return this->A[n + i - 1];
    if(i - j == 1)
        return this->A[j - 1];
    if(j - i == 1)
        return this->A[2*n - 1 + i - 1];
    return 0;
}

void TriDiagonal::Display(){
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            std::cout << Get(i, j) << " ";
        }
        std::cout <<std::endl;
    }
}

void TriDiagonal::Create(){
    std::cout <<"Please enter the Triangle Matrix:\n";
    int x = 0;
    for(int i = 1; i <= this->n; i++){
        for(int j = 1; j <= this->n; j++){
            std::cin >> x;
            this->Set(i, j, x);
        }
    }
}
