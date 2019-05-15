#include <iostream>
#include<BST.h>
using namespace std;

int main()
{
    cout << "Binary Search Tree:" << endl;
    BST bst;
    bst.InsertIter(10);
    bst.InsertIter(7);
    bst.InsertIter(4);
    bst.InsertIter(2);
    bst.InsertIter(11);
    bst.InsertIter(18);
    bst.InsertIter(22);
    bst.InsertIter(45);
    if(bst.SearchIter(45))
        cout<<"45 exist"<<endl;
    if(bst.SearchIter(22))
        cout<<"22 exist"<<endl;
    if(bst.SearchIter(18))
        cout<<"18 exist"<<endl;
    if(bst.SearchIter(11))
        cout<<"11 exist"<<endl;
    if(bst.SearchIter(2))
        cout<<"2 exist"<<endl;

    if(bst.SearchIter(78))
        cout<<"78 exist"<<endl;
    else
        cout<<"78 Not exist"<<endl;

    bst.Display();

    return 0;
}
