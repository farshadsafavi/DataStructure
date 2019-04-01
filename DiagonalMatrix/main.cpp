#include <iostream>
#include<Diagonal.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Diagonal d(4);
    d.Set(1, 1, 5);
    d.Set(2, 2, 8);
    d.Set(3, 3, 9);
    d.Set(4, 4, 12);
    cout <<d.Get(2, 2) << endl;
    d.Display();
    return 0;
}
