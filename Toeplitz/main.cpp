#include <iostream>
#include<ToeplitsMatrix.h>
using namespace std;

int main()
{
    cout << "Create Toeplits:" << endl;
    cout <<"Please enter the matrix dimension:";
    int n = 0;
    cin >> n;
    int ch;
    ToeplitsMatrix tm(n);
    do{
        cout <<"Please enter the option:"<<endl;
        cout <<"1 - Create a toeplits matrix"<<endl;
        cout <<"2 - Get the value given i and j"<<endl;
        cout <<"3 - Display matrix"<<endl;
        cout <<"0 - To terminate!"<<endl;
        cin >> ch;
        switch(ch){
        case 1:
            tm.Create();
            break;
        case 2:
            cout <<"please enter i and j:";
            int i, j;
            cin >>i>>j;
            cout <<tm.Get(i, j) <<endl;;
            break;
        case 3:
            tm.Display();
            break;
        case 0:
            break;
        }

    }while(ch != 0);


    tm.Display();
    return 0;
}
