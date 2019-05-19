#include "AVL.h"

AVL::AVL()
{
    root = nullptr;
}

Node* AVL::Insert(int data){
   return Insert(data, root);
}

int AVL::NodeHeight(Node *c){
    int left_height = (c && c->left)?c->left->height:0;
    int right_height = (c && c->right)?c->right->height:0;
    return (left_height > right_height)? left_height + 1:right_height+ 1;
}

int AVL::BalanceFactor(Node *c){
    int left_height = (c && c->left)?c->left->height:0;
    int right_height = (c && c->right)?c->right->height:0;
    return (left_height - right_height);
}

Node* AVL::LLRotation(Node *c){
    Node *cl = c->left;
    Node *clr = cl->right;

    cl->right = c;
    c->left = clr;

    c->height = NodeHeight(c);
    cl->height = NodeHeight(cl);

    if(c == root)
        root = cl;
    return c;

}

Node* AVL::Insert(int data, Node *c){
    Node *t = new Node();
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    if(root == nullptr){
        root = t;
        root->height = 1;
        c = root;
    } else if(data < c->data){
        if(c->left){
            return Insert(data, c->left);
        } else{
            c->left = t;
        }
    } else if(data > c->data){
        if(c->right){
            return Insert(data, c->right);
        } else{
            c->right = t;
        }
    }
    c->height = NodeHeight(c);
    cout << BalanceFactor(c) << endl;
    cout << BalanceFactor(c->left) << endl;
    if(BalanceFactor(c) == 2 && BalanceFactor(c->left) == 1){
        return LLRotation(c);
    }
    return c;

}

void AVL::Display(){
    if(root)
        Display(root);
    cout <<endl;
}

void AVL::Display(Node *c){
    if(c){
        Display(c->left);
        cout << c->data <<" ";
        Display(c->right);

    }
}

AVL::~AVL()
{
    //dtor
}
