#include <iostream>
#include<BT.h>
using namespace std;


int main()
{
    cout << "Generate a tree from preorder and inorder list!" << endl;

    BT bt;
    int preorder[9] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int Inorder[9] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    Node *root = bt.BuildTree(Inorder, preorder, 0, 8);
    bt.Display(root);
    cout <<endl;

    BT bt1;
    int post[9] = {6, 3, 9, 7, 8, 5, 1, 2, 4};
    int i = 8;
    root = bt1.BuildTreePost(Inorder, post, 0, 8, &i);
    bt1.Display(root);
    cout << endl;
    cout <<"Number node is:" << bt1.NumberOfNodes(root) << endl;
    cout <<"Sum is:" << bt1.Sum(root) << endl;
    cout <<"Height is:" << bt1.Height(root) << endl;
    cout <<"Number one degree nodes is:" << bt1.NumberOfOneDegreeNodes(root) << endl;
    cout <<"Number two degree nodes is:" << bt1.NumberOfTwoDegreeNodes(root) << endl;
    cout <<"Number of leafs:" << bt1.NumberOfLeafs(root)<< endl;

    return 0;
}
