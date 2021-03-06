#include <iostream>
#include<BST.h>
using namespace std;
#include<stack>

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
    cout <<"Height is:"<<bst.Height() <<endl;



    bst.Delete(7);
    bst.Display();
    bst.Delete(4);
    bst.Display();
    bst.Delete(2);
    bst.Display();
    bst.Delete(11);
    bst.Display();
    bst.Delete(18);
    bst.Display();
    bst.Delete(22);
    bst.Display();
    bst.Delete(45);
    bst.Display();

    int pre[8] = {30, 20, 10, 15, 25, 40, 50, 45};
    bst.CreatePre(pre, 8);
    bst.Display();
    return 0;
}
