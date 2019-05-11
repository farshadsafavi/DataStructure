#ifndef BT_H
#define BT_H
#include<list>
#include<stack>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    bool isVisited;
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
        void PreorderIter();
        void InorderIter();
        void PostorderIter();
        void PostorderIter2();
        virtual ~BT();
};

#endif // BT_H
