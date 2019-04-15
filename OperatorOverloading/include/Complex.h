#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int img;
    public:
        Complex();
        Complex(int real, int img);
        Complex Add(Complex c);
        //Complex operator+(Complex c);
        friend Complex operator+(Complex c1, Complex c2);
        void Display();
        virtual ~Complex();
};

#endif // COMPLEX_H
