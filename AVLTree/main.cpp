#include <iostream>
#include<AVL.h>
using namespace std;

int main()
{
    cout << "AVL Tree!" << endl;
    AVL avl;
    avl.Insert(30);
    avl.Display();
    avl.Insert(20);
    avl.Display();
    avl.Insert(10);
    avl.Display();

    return 0;
}
