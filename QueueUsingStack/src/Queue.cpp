#include "Queue.h"

Queue::Queue()
{
    //ctor
}

void Queue::Enqueue(int x){
    this->s1.push(x);
}

int Queue::Dequeue(){
    int x = -1;
    if(this->s2.empty()){
        while(!this->s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    x = s2.top();
    s2.pop();
    return x;
}

bool Queue::isEmpty(){
    return this->s1.empty() && this->s2.empty();
}

int Queue::Size(){
    return s1.size() + s2.size();
}

void Queue::Display(){
    while(!s1.empty()){
        cout << s1.top() << endl;
        s1.pop();
    }

    while(!s2.empty()){
        cout << s2.top() << endl;
        s2.pop();
    }
}


Queue::~Queue()
{
    //dtor
}
