#ifndef SPARSE_H
#define SPARSE_H
#include<Element.h>

class Sparse
{
    private:
        int row;
        int col;
        int num;
        Element *e;
    public:
        Sparse(int row, int col, int num);
        void Create();
        friend Sparse operator+(Sparse &s1, Sparse &s2);
        void Display();
        virtual ~Sparse();


};

#endif // SPARSE_H
