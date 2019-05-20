#include <iostream>
#include<QudraticProbing.h>
using namespace std;

int main()
{
    cout << "Quadratic Probing Hashing:" << endl;
    QudraticProbing HT(10);
    HT.Insert(5);
    HT.Insert(15);
    HT.Insert(25);
    HT.Insert(35);
    HT.Insert(45);
    HT.Insert(55);
    HT.Display();
    int table[9] = {5, 15, 25, 35, 45, 55, 65, 76, 30};
    for(int i = 0; i < 9;i++){
        if(HT.Search(table[i]) == -1)
            cout <<"Not found!"<< endl;
        else{
            cout << HT.Search(table[i]) <<" found!" << endl;
        }
    }
    return 0;
}
