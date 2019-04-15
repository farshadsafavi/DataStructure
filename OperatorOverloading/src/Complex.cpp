#include "Complex.h"
Complex::Complex()
{
    this->real = 0;
    this->img = 0;
}

Complex::Complex(int real, int img)
{
    this->real = real;
    this->img = img;
}


Complex Complex::Add(Complex c){
    Complex res;
    res.real = this->real + c.real;
    res.img = this->img + c.img;
    return res;
}
/*
Complex Complex::operator+(Complex c){
    Complex res;
    res.real = this->real + c.real;
    res.img = this->img + c.img;
    return res;
}*/

Complex operator+(Complex c1,Complex c2){
     Complex temp;
     temp.real=c1.real+c2.real;
     temp.img=c1.img+c2.img;
     return temp;
}

void Complex::Display(){
    cout <<this->real <<" + i" <<this->img <<endl;
}

Complex::~Complex()
{
    //dtor
}
