#include "BST.h"

BST::BST()
{
    root = nullptr;
}

void BST::Insert(int data){
    Insert(root, data);
}

void BST::Insert(Node *c, int data){
    Node *n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    if(c == nullptr){
        root = n;
    } else{
       if(data < c->data){
            if(c->left){
                Insert(c->left, data);
            }else{
                c->left = n;
            }
       } else{
           if(c->right){
                Insert(c->right, data);
            }else{
                c->right = n;
            }
       }
    }
}

void BST::InsertIter(int data){
    Node *n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    if(root == nullptr){
        root = n;
        return;
    }
    Node* c = root;
    Node* p = c;
    while(c != nullptr){
        if(data < c->data){
            if(c->left){
                c = c->left;
                p = c;
            } else{
                p->left = n;
                return;
            }
        } else{
            if(c->right){
                c = c->right;
                p = c;
            } else{
                p->right = n;
                return;
            }
        }
    }
}

bool BST::Search(Node *c, int data){
    if(c->data == data){
        return true;
    } else{
        if(data < c->data){
            if(c->left)
                Search(c->left, data);
            else
                return false;
        } else{
            if(c->right)
                Search(c->right, data);
            else
                return false;
        }
    }
}

bool BST::Search(int data){
    if(root != nullptr){
        return Search(root, data);
    } else{
        return false;
    }
}

bool BST::SearchIter(int data){
    if(root == nullptr){
        return false;
    } else{
        Node *c = root;
        while(c != nullptr){
            if(c->data == data){
                return true;
            } else{
                if(data < c->data){
                    if(c->left)
                        c = c->left;
                    else
                        return false;
                } else{
                    if(c->right)
                        c = c->right;
                    else
                        return false;

                }
            }
        }
    }
}

void BST::Display(Node *c){
    if(c){
        Display(c->left);
        cout <<c->data <<" ";
        Display(c->right);
    }
}

void BST::Display(){
    if(root){
        Display(root);
    }
    cout << endl;
}

BST::~BST()
{
    //dtor
}
