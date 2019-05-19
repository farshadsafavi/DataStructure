#ifndef HASHTABLELL_H
#define HASHTABLELL_H
#include<list>
#include<iterator>
#include<iostream>
using namespace std;


class HashTableLL
{
    private:
        list<int>* HT;
        int Size;
        int HashFunction(int key);
    public:
        HashTableLL(int Size);
        void HashInsert(int key);
        bool Search(int key);
        void Delete(int key);
        void Display();
        virtual ~HashTableLL();

};

#endif // HASHTABLELL_H
