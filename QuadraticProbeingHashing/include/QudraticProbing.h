#ifndef QUDRATICPROBING_H
#define QUDRATICPROBING_H
#include<iostream>
using namespace std;

class QudraticProbing
{
    private:
        int *HT;
        int Size;
        int Count;
        int HashFunction(int key);
    public:
        QudraticProbing(int Size);
        void Insert(int key);
        int Search(int key);
        void Display();
        virtual ~QudraticProbing();
};

#endif // QUDRATICPROBING_H
