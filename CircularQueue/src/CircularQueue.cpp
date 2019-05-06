#include "CircularQueue.h"

CircularQueue::CircularQueue()
{
    this->Size = 10;
    this->fr = 0;
    this->r = 0;
    this->Q = new int[Size];
}

CircularQueue::CircularQueue(int Size)
{
    this->Size = Size;
    this->fr = 0;
    this->r = 0;
    this->Q = new int[Size];
}

void CircularQueue::Enqueue(int x){
    if((this->r + 1)%this->Size == this->fr){
        cout <<"The Queue is full!" << endl;
        return;
    } else{
        this->r = (this->r + 1) % this->Size;
        this->Q[this->r] = x;
    }
}

int CircularQueue::Dequeue(){
    int x = -1;
    if(this->fr == this->r){
        cout <<"The Queue is empty!"<< endl;
    } else{
        this->fr = (this->fr + 1) % this->Size;
        x = this->Q[this->fr];
    }
    return x;
}

void CircularQueue::Display(){
   int i = this->fr;
   while(i != this->r){
        i = (i + 1)%this->Size;
        cout <<this->Q[i] <<" ";
   }
   cout <<"\n";
}

CircularQueue::~CircularQueue()
{
    delete []Q;
}
