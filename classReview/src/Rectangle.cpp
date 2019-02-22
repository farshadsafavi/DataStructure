#include "Rectangle.h"

Rectangle::Rectangle(int l, int b)
{
    this->length = l;
    this->breadth = b;
}

int Rectangle::area(){
    return this->length*this->breadth;
}

void Rectangle::changeLength(int l){
    this->length = l;
}

Rectangle::~Rectangle()
{

}
