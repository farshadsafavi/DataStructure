#ifndef AVL_H
#define AVL_H
#include<iostream>
using namespace std;
struct Node{
    int data;
    int height;
    Node* left;
    Node* right;
};

class AVL
{
    private:
        Node* root;
        Node* Insert(int data, Node *c);
        void Display(Node* c);
        int NodeHeight(Node* c);
        int BalanceFactor(Node* c);
        Node* LLRotation(Node *c);
    public:
        AVL();
        Node* Insert(int data);
        void Display();
        virtual ~AVL();
};

#endif // AVL_H
