#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED
template<class T>
Stack<T>::Stack(int Size)
{
    this->Size = Size;
    this->top = -1;
    this->s = new T[Size];
}

template<class T>
void Stack<T>::Push(T x){
    if(this->top == this->Size - 1){
        cout <<"Stack overflow!"<<endl;
    } else{
        this->top++;
        this->s[this->top] = x;
    }
}

template<class T>
T Stack<T>::Pop(){
    int x = -1;
    if(this->top == - 1){
        cout <<"Stack underflow!"<<endl;
    } else{
        x = this->s[this->top--];
    }
    return x;
}

template<class T>
void Stack<T>::Display(){
    for(int i = this->top; i >= 0 ; i--){
        cout << this->s[i] <<" ";
    }
    cout <<"\n";
}

template<class T>
T Stack<T>::Peek(int pos){
    T x = -1;
    int Index = this->top - pos + 1;
    if(Index < 0){
        cout <<"Stack underflow!"<<endl;
    } else{
        x = this->s[Index];
    }
    return x;
}

template<class T>
bool Stack<T>::isEmpty(){
    return this->top == -1;
}

template<class T>
bool Stack<T>::isFull(){
    return this->top = this->Size -1;
}

template<class T>
T Stack<T>::StackTop(){
    if(this->isEmpty()) return -1;
    return this->s[this->top];
}

template<class T>
Stack<T>::~Stack()
{
    delete []s;
}

#endif // IMPLEMENTATION_H_INCLUDED
