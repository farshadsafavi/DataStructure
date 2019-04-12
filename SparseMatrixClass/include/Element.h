#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>
using namespace std;

class Element
{
    private:
        int i;
        int j;
        int val;
    public:
        Element();
        Element(int i, int j, int val);
        int get_i();
        int get_j();
        int get_val();
        void set_val(int val);
        virtual ~Element();

};

#endif // ELEMENT_H
