#include <iostream>
#include <Sparse.h>
using namespace std;


int main()
{
    cout << "Sparse Matrix:" << endl;
    cout <<"Please enter First Matrix the dimensions(row and column):";
    int row, col, num;
    cin >> row >> col;
    cout <<"Please enter number of elements:";
    cin >> num;
    Sparse s1(row, col, num);
    s1.Create();
    cout <<s1<<endl;
    cout <<"Please enter Second Matrix the dimensions(row and column):";
    int row2, col2, num2;
    cin >> row2 >> col2;
    cout <<"Please enter number of elements:";
    cin >> num2;
    Sparse s2(row2, col2, num2);
    s2.Create();
    cout <<s2<<endl;;
    cout <<"Result:\n";
    Sparse s3 = s1 + s2;
    cout <<s3<<endl;
    return 0;
}
