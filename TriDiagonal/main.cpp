#include <iostream>
#include<TriDiagonal.h>
using namespace std;

int main()
{
    cout << "Tri-Diagonal:" << endl;
    int n;
    cout <<"Please enter the dimension:";
    cin >> n;
    TriDiagonal td(n);
    //td.Create();


    int ch = 0;
    do{
        ch = 0;
        cout <<"Please enter the choice:\n";
        cout <<"1: Create a new matrix\n";
        cout <<"2: Get the element given i, j\n";
        cout <<"3: Display the value:\n";
        cout <<"0: Terminate!:\n";
        cin >> ch;
        int x = 0;
        switch(ch){
            case 1:
                td.Create();
                break;
            case 2:
                cout <<"Please enter i and j:\n";
                int i, j;
                cin >> i >> j;
                cout << td.Get(i, j) << endl;
                break;
            case 3:
                td.Display();
                break;
        }
    } while(ch != 0);

    //td.Display();

    return 0;
}
