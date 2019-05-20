#include "HashTable.h"

HashTable::HashTable(int Size)
{
    this->Size = Size;
    HT = new int[this->Size];
    this->Count = 0;
    for(int i = 0; i < this->Size; i++){
        HT[i] = -1;
    }
}

HashTable::HashFunction(int key){
    return key%10;
}

void HashTable::Insert(int key){
    int Index = HashFunction(key);
    int i = 0;
    if(Count > Size/2) return;
    while(HT[(Index + i)%Size] != -1){
        i++;
    }
    HT[(Index + i)%Size] = key;
    Count++;
}

void HashTable::Display(){
    for(int i = 0; i < this->Size; i++){
        if(HT[i] != -1)
            std::cout <<HT[i] << " ";
    }
    std::cout << std::endl;
}

int HashTable::Search(int key){
    int Index = HashFunction(key);
    int i = 0;
    while(HT[(Index + i)%Size] != key){
        if(HT[(Index + i)%Size] == -1) return -1;
        i++;
    }
    return HT[(Index + i)%Size];
}

HashTable::~HashTable()
{
    //dtor
}
