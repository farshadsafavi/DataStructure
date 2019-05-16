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
        Node* Delete(Node* c, int data);
        bool Search(Node* c, int data);
        void Display(Node* c);
        void Insert(Node*c, int data);
        int Height(Node *c);
        Node* InordrePredecessor(Node *c);
        Node* InorderSuccessor(Node *c);
    public:
        BST();
        void Insert(int data);
        void InsertIter(int data);
        void Display();
        bool SearchIter(int data);
        bool Search(int data);
        Node* Delete(int data);
        int Height();
        virtual ~BST();

};

#endif // BST_H
