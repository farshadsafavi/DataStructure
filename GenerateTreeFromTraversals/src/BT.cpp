#include "BT.h"

BT::BT()
{
    this->root = nullptr;
}

Node* BT::BuildTree(int In[],int Pre[], int Start, int End){
    static int i = 0;

    if(Start > End)
        return nullptr;

    int r = Pre[i++];
    Node* t = new Node();
    t->data = r;
    if(Start == End)
        return t;
    int index = SearchIndex(In, Start, End, r);

    t->left = BuildTree(In,Pre, Start, index - 1);
    t->right = BuildTree(In,Pre, index + 1, End);
}

Node* BT::BuildTreePost(int In[],int Post[], int Start, int End, int* i){

    if(Start > End)
        return nullptr;

    int r = Post[*i];
    (*i)--;
    Node* t = new Node();
    t->data = r;
    if(Start == End)
        return t;

    int index = SearchIndex(In, Start, End, r);
    t->right = BuildTreePost(In,Post, index + 1, End, i);
    t->left = BuildTreePost(In,Post, Start, index - 1, i);

    return t;
}

int BT::SearchIndex(int In[], int Start,int End, int r){
    for(int i = Start; i <= End; i++){
        if(In[i] == r)
            return i;
    }
}

void BT::Display(){
    if(root != nullptr)
        Display(root);
    cout << endl;
}

void BT::Display(Node *c){
    if(c != nullptr){
        Display(c->left);
        cout << c->data <<" ";
        Display(c->right);
    }
}

BT::~BT()
{
    delete root;
}
