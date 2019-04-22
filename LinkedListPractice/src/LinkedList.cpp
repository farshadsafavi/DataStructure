#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    Node *c = head;
    Node *d;
    while(c){
        d = c;
        delete d;
        c = c->next;
    }
}

int LinkedList::Count(){
    Node *c = head;
    int cnt = 0;
    while(c){
        c++;
        c = c->next;
    }
    return cnt;
}

void LinkedList::Reverse(){
    Node *c = head;
    Node *p;
    Node *pp;
    while(c){
        pp = p;
        p = c;
        c = c->next;
        p->next = pp;
    }
    head = p;
}

void LinkedList::ReverseRec(){
    ReverseRec(NULL, head);
}

void LinkedList::ReverseRec(Node *p, Node *c){
    if(c != NULL){
        ReverseRec(c, c->next);
        c->next = p;
    } else{
        head = p;
    }
}

void LinkedList::Insert(int index, int value){
    Node *c = head;
    Node *p;
    Node *n = new Node(value, nullptr);
    if(index < 0 && index > Count()){
        return;
    }
    if(index == 0){
        n->next = c;
        head = n;
    }else{
        for(int i = 0; i < index; i++){
            p = c;
            c = c->next;
        }
        p->next = n;
        n->next = c;
    }

}

void LinkedList::Display(){
    Node *c = head;
    while(c){
        cout <<c->value <<" ";
        c = c->next;
    }
    cout <<"\n";
}
