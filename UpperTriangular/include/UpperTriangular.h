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
        void Set2(int i,int j, int x);
        int Get2(int i, int j);
        void Display2();
        int GetSymmetric(int i, int j);
        void DisplaySymmetric();
        virtual ~UpperTriangular();


};

#endif // UPPERTRIANGULAR_H
