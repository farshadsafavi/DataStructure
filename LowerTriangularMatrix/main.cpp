#include <iostream>
#include <TriangularMatrix.h>
using namespace std;

int main()
{
    cout << "Lower Triangular Matrix:" << endl;
    int d;
    cout <<"Enter Dimensions:";
    cin >>d;

    TriangularMatrix tm(d);

    int x;
    cout<<"Enter all elements:";
    for(int i = 1; i <= d; i++ ){
        for(int j = 1; j <= d; j++){
            cin >>x;
            tm.Set2(i, j, x);
        }
    }
    tm.Display2();
    cout <<"The Dimension is: " << tm.GetDimension() << endl;
    return 0;
}
