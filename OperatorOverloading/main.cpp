#include <iostream>
#include <Complex.h>
using namespace std;

int main()
{
    cout << "Complex number" << endl;
    Complex c1(3, 7);
    Complex c2(5, 4);
    Complex c3;

    c3 = c1.Add(c2);
    c3.Display();

    Complex c4(4, 7);
    Complex c5(6, 9);
    c3 = c4 + c5;
    c3.Display();

    return 0;
}
