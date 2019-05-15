#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;
struct Node{
    Node *left;
    Node *right;
    int data;
};

class BST
{
    private:
        Node *root;
    public:
        BST();
        void Insert(Node*c, int data);
        void Insert(int data);
        void InsertIter(int data);
        void Display();
        void Display(Node* c);
        bool Search(Node* c, int data);
        bool Search(int data);
        bool SearchIter(int data);
        virtual ~BST();


};

#endif // BST_H
