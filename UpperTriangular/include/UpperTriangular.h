#ifndef UPPERTRIANGULAR_H
#define UPPERTRIANGULAR_H
#include<iostream>
using namespace std;

class UpperTriangular
{
    private:
        int *A;
        int n;
        int Size;
    public:
        UpperTriangular(int n);
        void Set(int i,int j, int x);
        int Get(int i, int j);
        void Display();
        virtual ~UpperTriangular();


};

#endif // UPPERTRIANGULAR_H
