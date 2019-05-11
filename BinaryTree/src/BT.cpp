#include "BT.h"

BT::BT()
{
    this->root = nullptr;
}

void BT::create(){
    int x;
    list<Node*> Q;
    cout <<"Enter the Node:";
    cin >> x;
    Node *t = new Node();
    t->data = x;
    t->left = nullptr;
    t->right = nullptr;
    root = t;
    Q.push_back(root);
    while(!Q.empty()){
        Node *p = Q.front();
        Q.pop_front();
        cout <<"Enter the left child(-1 no left child):";
        cin >> x;
        if(x != -1){
            Node *t = new Node();
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            Q.push_back(t);
        }
        cout <<"Enter the right child(-1 no right child):";
        cin >> x;
        if(x != -1){
            Node *t = new Node();
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            Q.push_back(t);
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
    if(c != nullptr){
        cout <<c->data<<" ";
        Display(c->left);
        Display(c->right);
    }
}

void BT::PreorderIter(){
    stack<Node*> st;
    Node *c = root;
    while(c != nullptr || !st.empty()){
        if(c != nullptr){
            st.push(c);
            cout << c->data <<" ";
            c = c->left;
        } else{
            c = st.top();
            st.pop();
            c = c->right;
        }
    }
    cout <<"\n";
}

void BT::PostorderIter(){
    stack<Node*> st;
    stack<bool> visited;
    Node *c = root;
    while(c != nullptr || !st.empty()){
        if(c != nullptr){
            st.push(c);
            visited.push(false);
            c = c->left;
        } else{
            c = st.top();
            if(!visited.top()){
                visited.pop();
                visited.push(true);
            } else{
                st.pop();
                visited.pop();
                if(!c->isVisited){
                    cout << c->data <<" ";
                    c->isVisited = true;
                }
            }
            c = c->right;
        }
    }
    cout <<"\n";
}

void BT::PostorderIter2(){
    stack<Node*> st1;
    stack<Node*> st2;
    Node *c = root;
    st1.push(c);
    while(!st1.empty()){
        c = st1.top();
        st1.pop();
        st2.push(c);

        if(c->left)
            st1.push(c->left);
        if(c->right)
            st1.push(c->right);
    }

    while(!st2.empty()){
        c = st2.top();
        st2.pop();
        cout <<c->data <<" ";
    }
    cout <<"\n";
}

void BT::InorderIter(){
    Node *c = root;
    stack<Node*> stk;
    while(!stk.empty() || c != nullptr){
        if(c != nullptr){
            stk.push(c);
            c = c->left;
        } else{
            c = stk.top();
            stk.pop();
            cout <<c->data <<" ";
            c = c->right;
        }
    }
    cout <<"\n";
}

BT::~BT()
{
    delete this->root;
}
