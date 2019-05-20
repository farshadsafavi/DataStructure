#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
using namespace std;

class HashTable
{
    private:
        int *HT;
        int Size;
        int Count;
        int HashFunction(int key);
        int SecondHashFunction(int key);
    public:
        HashTable(int Size);
        void Insert(int key);
        int Search(int key);
        void Display();
        virtual ~HashTable();

    protected:


};

#endif // HASHTABLE_H
