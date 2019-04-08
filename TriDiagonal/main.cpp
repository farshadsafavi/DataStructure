#include <iostream>
#include<TriDiagonal.h>
using namespace std;

int main()
{
    cout << "Tri-Diagonal:" << endl;
    TriDiagonal td(4);
    //td.Create();
    cout <<"Please enter the Triangle Matrix:\n";
    int x;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            std::cin >> x;
            td.Set(i, j, x);
        }
    }

    td.Display();

    return 0;
}
