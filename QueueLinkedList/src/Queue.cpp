#include "Queue.h"

Queue::Queue()
{
    this->f = nullptr;
    this->r = nullptr;
}

void Queue::Enqueue(int x){
    Node *t = new Node();

    if(t == nullptr){
        cout <<"Heap is full!" << endl;
        return;
    }
    t->data = x;
    t->next = nullptr;
    if(this->f == nullptr){
        f = r = t;
    } else{
        r->next = t;
        r = t;
    }
}

int Queue::Dequeue(){
    int x = -1;
    if(f == nullptr){
        cout <<"Queue is empty!" << endl;
    } else{
        x = f->data;
        Node *temp = f;
        f = f->next;
        delete temp;
    }
    return x;
}

void Queue::Display(){
    Node *c = this->f;
    while(c != nullptr){
        cout <<c->data <<" ";
        c = c->next;
    }
    cout <<"\n";
}

Queue::~Queue()
{
    delete []f;
}
