#ifndef BT_H
#define BT_H
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};



class BT
{
    private:
        Node *root;

    public:
        BT();
        Node* BuildTree(int In[],int Pre[], int Start, int End);
        Node* BuildTreePost(int In[],int Post[], int Start, int End, int* i);
        int SearchIndex(int Pre[], int Start,int End, int r);
        void Display(Node* c);
        void Display();
        virtual ~BT();
};

#endif // BT_H
