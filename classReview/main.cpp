#include <iostream>
#include<Rectangle.h>
using namespace std;

int main()
{
    cout << "Class in C++:" << endl;
    Rectangle r(10, 15);
    cout << "area is: " << r.area() << endl;
    r.changeLength(20);
    cout << "area is: " << r.area() << endl;
    return 0;
}
