#ifndef ARITHMETIC_H
#define ARITHMETIC_H

template<class T>
class Arithmetic
{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a,T b);
        T add();
        T sub();
        virtual ~Arithmetic();
};

#endif // ARITHMETIC_H
#include "implementation.h"
