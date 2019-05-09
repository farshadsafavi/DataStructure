#include "BT.h"

BT::BT()
{
    this->root = nullptr;
}

void BT::create(){
    int x;
    queue<Node*> Q;
    cout <<"Enter the Node:";
    cin >> x;
    Node *t = new Node();
    t->data = x;
    t->left = nullptr;
    t->right = nullptr;
    root = t;
    Q.push(root);
    while(!Q.empty()){
        Node *p = Q.back();
        Q.pop();
        cout <<"Enter the left child(-1 no left child):";
        cin >> x;
        if(x != -1){
            Node *t = new Node();
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            Q.push(t);
        }
        cout <<"Enter the right child(-1 no right child):";
        cin >> x;
        if(x != -1){
            Node *t = new Node();
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            Q.push(t);
        }
    }
}

void BT::Display(){
    if(root != nullptr){
        Display(root);
    }
    cout <<"\n";
}

void BT::Display(Node *c){
    cout <<c->data<<" ";
    if(c->left != nullptr){
        Display(c->left);
    }

    if(c->right != nullptr){
        Display(c->right);
    }
}


BT::~BT()
{
    delete this->root;
}
