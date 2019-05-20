#include "QudraticProbing.h"

QudraticProbing::QudraticProbing(int Size)
{
    this->Count = 0;
    this->Size = Size;
    this->HT = new int[this->Size];
    for(int i = 0; i < Size;i++){
        HT[i] = -1;
    }
}


void QudraticProbing::Insert(int key){
    int Index = HashFunction(key);
    int i = 0;
    while(HT[(Index + i*i)%Size] != -1){
        i++;
    }
    HT[(Index + i*i)%Size] = key;
}

int QudraticProbing::Search(int key){
    int Index = HashFunction(key);
    int i = 0;
    while(HT[(Index + i*i)%Size] != key){
        if(HT[(Index + i*i)%Size] == -1) return -1;
        i++;
    }
    return HT[(Index + i*i)%Size];
}

void QudraticProbing::Display(){
    for(int i = 0; i < Size; i++){
        if(HT[i] != -1)
            cout <<HT[i] <<" ";
    }
    cout << endl;
}

int QudraticProbing::HashFunction(int key){
    return key % 10;
}



QudraticProbing::~QudraticProbing()
{

}
