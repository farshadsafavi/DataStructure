#include "Element.h"
Element::Element()
{
    this->i = 0;
    this->j = 0;
    this->val = 0;
}

Element::Element(int i, int j, int val)
{
    this->i = i;
    this->j = j;
    this->val = val;
}

Element::~Element()
{

}

int Element::get_i(){
    return this->i;
}

int Element::get_j(){
    return this->j;
}

int Element::get_val(){
    return this->val;
}

void Element::set_val(int val){
    this->val = val;
}
