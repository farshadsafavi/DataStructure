#include "HashTable.h"

HashTable::HashTable(int Size)
{
    this->Count = 0;
    this->Size = Size;
    this->HT = new int[this->Size];
    for(int i = 0; i < Size;i++){
        HT[i] = -1;
    }
}

void HashTable::Insert(int key){
    int Index = HashFunction(key);
    int i = 0;
    while(HT[(Index + i*SecondHashFunction(key))%Size] != -1){
        i++;
    }
    HT[(Index + i*SecondHashFunction(key))%Size] = key;
}

int HashTable::Search(int key){
    int Index = HashFunction(key);
    int i = 0;
    while(HT[(Index + i*SecondHashFunction(key))%Size] != key){
        if(HT[(Index + i*SecondHashFunction(key))%Size] == -1) return -1;
        i++;
    }
    return HT[(Index + i*SecondHashFunction(key))%Size];
}

void HashTable::Display(){
    for(int i = 0; i < Size; i++){
        if(HT[i] != -1)
            cout <<HT[i] <<" ";
    }
    cout << endl;
}

int HashTable::HashFunction(int key){
    return key % 10;
}

int HashTable::SecondHashFunction(int key){
    return 7 - (key % 7);
}


HashTable::~HashTable()
{
    //dtor
}
