#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>

class HashTable
{
    private:
        int *HT;
        int Size;
        int Count;
        int HashFunction(int key);
    public:
        HashTable(int Size);
        void Insert(int key);
        void Display();
        int Search(int key);
        virtual ~HashTable();
};

#endif // HASHTABLE_H
