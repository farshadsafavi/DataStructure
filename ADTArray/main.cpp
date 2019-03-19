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


    return 0;
}
