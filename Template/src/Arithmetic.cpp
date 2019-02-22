#include "Arithmetic.h"
template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add(){
    return this->a + this->b;
}

template<class T>
T Arithmetic<T>::sub(){
    return this->a - this->b;
}

template<class T>
Arithmetic<T>::~Arithmetic()
{
    //dtor
}
