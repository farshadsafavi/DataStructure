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


Node* BST::Delete(int data){
    if(root != nullptr){
        return Delete(root, data);
    }
    return nullptr;
}

Node* BST::Delete(Node *c, int data){
    Node* q;
    if(c == nullptr){
        return nullptr;
    }

    if(c->left == nullptr && c->right == nullptr){
        if(c == root)
            delete(root);
        delete(c);
        return nullptr;
    }

    if(data < c->data){
        c->left = Delete(c->left, data);
    } else if (data > c->data){
        c->right = Delete(c->right, data);
    } else{
        if(Height(c->left) > Height(c->right)){
            q = InordrePredecessor(c->left);
            c->data = q->data;
            c->left = Delete(c->left, q->data);
        } else{
            q = InorderSuccessor(c->right);
            c->data = q->data;
            c->right = Delete(c->right, q->data);
        }
    }
    return c;

}

Node* BST::InordrePredecessor(Node *n){
    Node *c = n;
    Node *p = c;
    while(c != nullptr){
        p = c;
        c = c->right;
    }
    return p;
}

Node* BST::InorderSuccessor(Node *n){
    Node *c = n;
    Node *p = c;
    while(c != nullptr){
        p = c;
        c = c->left;
    }
    return p;
}

int BST::Height(Node *c){
    int x = 0;
    int y = 0;
    if(c != nullptr){
        x = Height(c->left);
        y = Height(c->right);
        if(x > y){
            return x + 1;
        } else{
            return y + 1;
        }
    }
    return 0;
}

int BST::Height(){
    if(root != nullptr){
        return Height(root);
    }
    return 0;
}

void BST::CreatePre(int pre[], int n){
    int i = 0;
    stack<Node*> stk;
    Node *c = nullptr;
    while(i < n){
        Node *t = new Node();
        t->left = nullptr;
        t->right = nullptr;
        t->data = pre[i];
        if(c == nullptr){
            c = t;
            root = t;
            stk.push(t);
            i++;
        }else if(pre[i] < c->data){
            c->left = t;
            stk.push(t);
            c = c->left;
            i++;
        } else if(stk.empty() || pre[i] > c->data && pre[i] < stk.top()->data){
            c->right = t;
            c = c->right;
            i++;
        } else {
            if(!stk.empty() && pre[i] > c->data && pre[i] > stk.top()->data){
                c = stk.top();
                stk.pop();
            }
        }
    }
}

BST::~BST()
{
    //dtor
}
