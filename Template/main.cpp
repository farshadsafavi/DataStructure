#include <iostream>
#include<Arithmetic.h>
using namespace std;

int main()
{
    cout << "Template Example:" << endl;
    Arithmetic<int> ar(10, 7);
    cout << "add: " << (int)ar.add() << " sub: " << (int)ar.sub() << endl;
    Arithmetic<double> ar1(10.5, 7.3);
    cout << "add: " << (double)ar1.add() << " sub: " << (double)ar1.sub() << endl;
    return 0;
}
