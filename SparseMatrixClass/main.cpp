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
    s1.Display();
    cout <<"Please enter Second Matrix the dimensions(row and column):";
    int row2, col2, num2;
    cin >> row2 >> col2;
    cout <<"Please enter number of elements:";
    cin >> num2;
    Sparse s2(row2, col2, num2);
    s2.Create();
    s2.Display();
    cout <<"Result:\n";
    Sparse *s3 = s3->Add(&s1, &s2);
    s3->Display();
    return 0;
}
