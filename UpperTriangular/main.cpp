#include <iostream>
#include<UpperTriangular.h>
using namespace std;

int main()
{
    cout << "Upper Triangular Matrix:" << endl;
    int d;
    cout << "Enter the dimension:";
    cin >> d;
    UpperTriangular um(d);
    cout << "Enter the elements:\n";
    int x;
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            cin >> x;
            um.Set(i, j, x);
        }
    }
    cout <<"\n\n";
    um.Display();
    return 0;
}
