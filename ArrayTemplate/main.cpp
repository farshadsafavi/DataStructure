#include <iostream>
#include<Arrays.h>
using namespace std;

int main()
{
    cout << "Array Template:" << endl;
    Arrays<int> arr(10);
    arr.Insert(0, 5);
    arr.Insert(1, 6);
    arr.Insert(2, 9);
    arr.Display();
    cout <<arr.Delete(0) <<endl;
    arr.Display();
    cout <<arr.Delete(0) <<endl;
    cout <<arr.Delete(0) <<endl;
    cout <<arr.Delete(0) <<endl;
    cout <<arr.Delete(0) <<endl;

    Arrays<float> arr2(10);
    arr2.Insert(0, 5.2);
    arr2.Insert(1, 6.4);
    arr2.Insert(2, 9.1);
    arr2.Display();
    cout <<arr2.Delete(0) <<endl;
    arr2.Display();
    cout <<arr2.Delete(0) <<endl;
    cout <<arr2.Delete(0) <<endl;

    Arrays<char> arr3(10);
    arr3.Insert(0, 'a');
    arr3.Insert(1, 'b');
    arr3.Insert(2, 'c');
    arr3.Display();
    cout <<arr3.Delete(0) <<endl;
    arr3.Display();
    cout <<arr3.Delete(0) <<endl;
    cout <<arr3.Delete(0) <<endl;
    return 0;
}
