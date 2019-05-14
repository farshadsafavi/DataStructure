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

int BT::NumberOfNodes(Node *c){
    int x = 0;
    int y = 0;
    if(c){
       x = NumberOfNodes(c->left);
       y = NumberOfNodes(c->right);
       return x + y + 1;
    }
    return 0;
}

int BT::NumberOfTwoDegreeNodes(Node *c){
    int x = 0;
    int y = 0;
    if(c){
        x = NumberOfTwoDegreeNodes(c->left);
        y = NumberOfTwoDegreeNodes(c->right);
        if(c->left != nullptr && c->right != nullptr){
            return x + y + 1;
        } else{
            return y + x;
        }
    }
    return 0;
}

int BT::NumberOfOneDegreeNodes(Node *c){
    int x = 0;
    int y = 0;
    if(c){
        x = NumberOfOneDegreeNodes(c->left);
        y = NumberOfOneDegreeNodes(c->right);
        // c->left != nullptr ^ c->right != nullptr
        if((c->left != nullptr && c->right == nullptr) || (c->left == nullptr && c->right != nullptr)){
            return x + y + 1;
        } else{
            return y + x;
        }
    }
    return 0;
}

int BT::NumberOfLeafs(Node *c){
    int x = 0;
    int y = 0;
    if(c){
        x = NumberOfLeafs(c->left);
        y = NumberOfLeafs(c->right);
        if(x == 0 && y == 0){
            return x + y + 1;
        } else{
            return y + x;
        }
    }
    return 0;
}

int BT::Height(Node *c){
    int x = 0;
    int y = 0;
    if(c){
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

int BT::Sum(Node* c){
    int x = 0;
    int y = 0;
    if(c){
        x = Sum(c->left);
        y = Sum(c->right);
        return x + y + c->data;
    }
    return 0;
}

BT::~BT()
{
    delete root;
}
