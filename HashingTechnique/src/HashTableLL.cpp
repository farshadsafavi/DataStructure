#include "HashTableLL.h"


HashTableLL::HashTableLL(int Size)
{
    this->Size = Size;
    HT = new list<int>[Size];
}

int HashTableLL::HashFunction(int key){
    return key%10;
}

void HashTableLL::HashInsert(int key){
    int Index = HashFunction(key);
    HT[Index].push_back(key);
}

void HashTableLL::Display(){
    for(int i = 0; i < this->Size; i++){
        for (list<int>::iterator it=HT[i].begin(); it != HT[i].end(); ++it){
            cout << i << ":"<<*it << endl;
        }
    }
}

bool HashTableLL::Search(int key){
    int Index = HashFunction(key);
    for (list<int>::iterator it=HT[Index].begin(); it != HT[Index].end(); ++it){
            if(*it == key)
                return true;
    }
    return false;
}

void HashTableLL::Delete(int key){
    int Index = HashFunction(key);
    HT[Index].remove(key);
}



HashTableLL::~HashTableLL()
{
    //dtor
}
