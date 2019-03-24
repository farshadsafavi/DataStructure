#include "Array.h"

Arrays::Arrays()
{
    this->A = new int[10];
    this->Size = 10;
    this->length = 0;
}

Arrays::Arrays(int Size)
{
    this->A = new int[Size];
    this->Size = Size;
    this->length = 0;
}

void Arrays::Display(){
    for(int i = 0; i < this->length; i++){
        cout << this->A[i] <<" ";
    }
    cout <<endl;
}

void Arrays::Insert(int index, int value){
    if(index >= 0 && index < this->length){
        for(int i = this->length - 1; i >= index; i--){
            this->A[i + 1] = this->A[i];
        }
        cout <<"Insert" <<endl;
        this->A[index] = value;
        this->length++;
    }
}

int Arrays::Delete(int index){
    int res;
    if(index >= 0 && index < this->length){
        res = this->A[index];
        for(int i = index; i < this->length - 1; i++){
            this->A[i] = this->A[i+1];
        }
        this->length--;
    }
    return res;
}

Arrays::~Arrays()
{
    cout <<"De-construct Array!"<<endl;
    delete []A;
}
