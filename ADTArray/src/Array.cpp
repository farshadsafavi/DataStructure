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
    if(index >= 0 && index <= this->length){
        for(int i = this->length - 1; i >= index; i--){
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

int Array::LinearSearch(int x){
    for(int i = 0; i < this->length; i++){
        if(this->A[i] == x) {
            cout << x <<" is found at index " << i << endl;
            return i;
        }
    }
    cout << x <<" NOT found!" << endl;
    return -1;
}

int Array::BinarySearch(int x){
    int low = 0;
    int high = this->length - 1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(this->A[mid] == x){
            cout << x <<" is found at index " << mid << endl;
            return mid;
        } else if(x < this->A[mid]){
            high = mid - 1;
        } else if(x > this->A[mid]){
            low = mid + 1;
        }
    }
    cout << x <<" NOT found!" << endl;
    return -1;
}

int Array::Get(int index){
    if(index >= 0 && index < this->length){
        return this->A[index];
    }
    return -1;
}

void Array::Set(int index, int x){
    if(index >= 0 && index < this->length){
        this->A[index] = x;
    }
}

int Array::Max(){
    if (this->length == 0) return -1;
    int Max = this->A[0];
    for(int i = 1; i < this->length; i++){
        if(this->A[i] > Max){
            Max = this->A[i];
        }
    }
    return Max;
}

int Array::Min(){
    if (this->length == 0) return -1;
    int Min = this->A[0];
    for(int i = 1; i < this->length; i++){
        if(this->A[i] < Min){
            Min = this->A[i];
        }
    }
    return Min;
}

int Array::Sum(){
    int total = 0;
    for(int i = 0; i < this->length; i++){
        total += this->A[i];
    }
    return total;
}

double Array::Average(){
    return (double) Sum()/this->length;
}


Array::~Array()
{
    cout <<"De-Construct array"<<endl;
    delete []this->A;
}
