#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED
template<class T>
Stack<T>::Stack()
{
    this->top = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
    Node<T> *n;
    while(top != nullptr){
        n = top;
        top = top->next;
        delete n;
    }
}

template<class T>
void Stack<T>::Push(int x){
    Node<T> *t = new Node<T>();
    if(t){
        t->data = x;
        t->next = top;
    }
    top = t;
}

template<class T>
T Stack<T>::Pop(){
    T x = -1;
    Node<T> *n;
    if(top != nullptr){
        n = top;
        top = top->next;
        x = n->data;
        delete n;
    }
    return x;
}

template<class T>
T Stack<T>::Peek(int pos){
    Node<T> *c = this->top;

    for(int i = 0;c != nullptr && i < pos - 1; i++){
        c = c->next;
    }
    if(c)
        return c->data;
    return -1;
}

template<class T>
bool Stack<T>::isEmpty(){
    return this->top == nullptr;
}

template<class T>
bool Stack<T>::isFull(){
    Node<T> *t = new Node<T>();
    if(t == nullptr) return false;
    else return true;
}

template<class T>
T Stack<T>::StackTop(){
    return this->top->data;
}

template<class T>
void Stack<T>::Display(){
    Node<T> *c = this->top;
    while(c != NULL){
        cout <<c->data <<" ";
        c = c->next;
    }
    cout <<"\n";
}




#endif // IMPLEMENTATION_H_INCLUDED
