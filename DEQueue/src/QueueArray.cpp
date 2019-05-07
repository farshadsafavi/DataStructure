#include "QueueArray.h"

QueueArray::QueueArray()
{
    this->f = -1;
    this->r = -1;
    this->Size = 5;
    this->Q = new int[this->Size];
}

QueueArray::QueueArray(int Size)
{
    this->f = -1;
    this->r = -1;
    this->Size = Size;
    this->Q = new int[this->Size];
}

int QueueArray::RemoveFirst(){
    int x = -1;
    if(this->r > this->f){
        this->f++;
        x = this->Q[this->f];
    } else {
        cout<<"The Queue is full" << endl;
    }
    return x;
}

void QueueArray::AddFirst(int x){
    if(this->f == -1){
        cout <<"There is no first element!"<< endl;
    } else{
        this->Q[f] = x;
        this->f--;
    }
}

int QueueArray::RemoveLast(){
    int x = -1;
    if(this->r == -1){
        cout <<"The Queue is empty" << endl;
    } else{
        x = this->Q[this->r];
        this->r--;
    }
    return x;
}

void QueueArray::AddLast(int x){
    if(this->r + 1 == this->Size){
        cout<<"The first is full" << endl;
    } else{
        this->r++;
        this->Q[r] = x;
    }
}

void QueueArray::Display(){
    for(int i = this->f + 1; i <= this->r; i++){
        cout <<this->Q[i] <<" ";
    }
    cout <<"\n";
}

QueueArray::~QueueArray()
{
    delete Q;
}
