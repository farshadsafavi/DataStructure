#include "Array.h"

Array::Array()
{
    this->A = new int[10];
    this->arraySize = 10;
    this->length = 0;
}

Array::Array(int arraySize){
    this->A = new int[arraySize];
    this->arraySize = arraySize;
    this->length = 0;
}

void Array::ArrayInfo(){
    cout << "Array Information:\n";
    cout << "\tArray size: " << this->arraySize << endl;
    cout << "\tArray length: " << this->length << endl;
    Display();
}

void Array::Append(int x){
    if(this->length < this->arraySize){
        this->A[this->length++] = x;
    }
}

void Array::Display(){
    cout <<"\tElements are:" << endl;
    cout <<"\t";
    for(int i = 0; i < this->length; i++){
        cout <<this->A[i] << " ";
    }
    cout <<endl;
}

void Array::Insert(int index, int x){
    if(index >= 0 && index < this->length){
        for(int i = this->length; i >= index; i--){
            this->A[i+1] = this->A[i];
        }
        this->A[index] = x;
        this->length++;
    }
}

int Array::Delete(int index){
    cout << "Delete index " << index << endl;
    if(index >= 0 && index < this->length){
        int a = this->A[index];
        for(int i = index; i < this->length; i++){
            this->A[i] = this->A[i+1];
        }
        this->length--;
        return a;
    }
    return -1;
}

Array::~Array()
{
    cout <<"De-Construct array"<<endl;
    delete []this->A;
}
