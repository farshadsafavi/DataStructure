#include <iostream>
#include <Array.h>

using namespace std;

int main()
{
    cout << "OOP for developing all array operations:" << endl;
    cout<<"Please enter the array size: ";
    int arraySize;
    cin >> arraySize;
    Array arr = Array(arraySize);
    for(int i = 0; i < 5; i++)
        arr.Append(i);
    arr.ArrayInfo();

    arr.Insert(0, 12);
    arr.ArrayInfo();
    arr.Insert(5, 14);
    arr.ArrayInfo();
    arr.Insert(2, 16);
    arr.ArrayInfo();
    arr.Insert(1, 18);
    arr.ArrayInfo();
    arr.Insert(0, 20);
    arr.ArrayInfo();

    for(int i = 0 ; i < 6; i++)
        arr.Delete(0);
    arr.ArrayInfo();

    cout << arr.LinearSearch(14) << endl;
    cout << arr.LinearSearch(2) << endl;
    cout << arr.LinearSearch(4) << endl;
    cout << arr.LinearSearch(10) << endl;
    cout << arr.LinearSearch(3) << endl;

    cout <<"Max:" <<arr.Max() << endl;
    cout <<"Min:" <<arr.Min() << endl;
    cout <<"Sum:" <<arr.Sum() << endl;
    cout <<"Average:" <<arr.Average() << endl;

    Array arr2 = Array(10);
    for(int i = 0; i < 10; i++)
        arr2.Append(i);
    for(int i = 0; i < 10; i++)
        arr2.BinarySearch(i);
    arr2.BinarySearch(10);
    arr2.BinarySearch(11);

    cout <<"Max:" <<arr2.Max() << endl;
    cout <<"Min:" <<arr2.Min() << endl;
    cout <<"Sum:" <<arr2.Sum() << endl;
    cout <<"Average:" <<arr2.Average() << endl;

    cout <<"Index 0 value is:" <<arr2.Get(0) << endl;
    cout <<"Index 1 value is:" <<arr2.Get(1) << endl;
    cout <<"Index 2 value is:" <<arr2.Get(2) << endl;
    cout <<"Index 3 value is:" <<arr2.Get(3) << endl;
    for(int i = 0 ; i < 10; i++)
        arr2.Set(i, 10 + i);
    for(int i = 0; i < 10; i++)
        cout << arr2.Get(i) <<endl;

    cout <<"Max:" <<arr2.Max() << endl;
    cout <<"Min:" <<arr2.Min() << endl;
    cout <<"Sum:" <<arr2.Sum() << endl;
    cout <<"Average:" <<arr2.Average() << endl;
    return 0;
}
