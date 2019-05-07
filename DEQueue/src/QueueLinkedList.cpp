#include "QueueLinkedList.h"

QueueLinkedList::QueueLinkedList()
{
    this->first = nullptr;
    this->last = nullptr;
}

QueueLinkedList::~QueueLinkedList()
{
    delete first;
    delete last;
}

void QueueLinkedList::AddFirst(int x){
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    t->prev = nullptr;
    if(this->last == nullptr && this->first == nullptr){
        first = t;
        last = t;
    } else{
        t->next = first;
        first->prev = t;
        first = t;
    }
}

int QueueLinkedList::RemoveFirst(){
    int x = -1;
    if(this->first == nullptr){
        cout<<"The Q is empty!" << endl;
    } else{
        Node *temp = first;
        first = first->next;
        if(first != nullptr)
            first->prev = nullptr;
        else
            last = nullptr;
        x = temp->data;
        delete temp;
    }
    return x;
}

void QueueLinkedList::AddLast(int x){
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    t->prev = nullptr;
    if(this->last == nullptr && this->first == nullptr){
        first = t;
        last = t;
    } else{
        last->next = t;
        t->prev = last;
        last = t;
    }
}

int QueueLinkedList::RemoveLast(){
    int x = -1;
    if(this->last == nullptr){
        cout<<"The Q is empty!" << endl;
    } else{
        Node *temp = last;
        last = last->prev;
        if(last != nullptr)
            last->next = nullptr;
        else
            first = nullptr;
        x = temp->data;
        delete temp;
    }
    return x;
}


void QueueLinkedList::Display(){
    Node *c = first;
    if(first == nullptr) return;
    while(c != nullptr){
        cout<<c->data <<" ";
        c = c->next;
    }
    cout <<"\n";
}
