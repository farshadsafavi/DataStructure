#ifndef BT_H
#define BT_H
#include<queue>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BT
{
    private:
        Node *root;
    public:
        BT();
        void create();
        void Display();
        void Display(Node *c);
        virtual ~BT();
};

#endif // BT_H
