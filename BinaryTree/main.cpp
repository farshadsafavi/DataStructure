#include <iostream>
#include<BT.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    BT bt;
    bt.create();
    //bt.Display();
    //bt.PreorderIter();
    //bt.InorderIter();
    //bt.PostorderIter();
    //bt.PostorderIter2();
    bt.Levelorder();

    return 0;
}
