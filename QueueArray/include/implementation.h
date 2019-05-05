#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED
template<class T>
Queue<T>::Queue()
{
    this->fr = -1;
    this->rear = -1;
    this->Size = 10;
    this->Q = new T[this->Size];
}

template<class T>
Queue<T>::Queue(int Size)
{
    this->fr = -1;
    this->rear = -1;
    this->Size = Size;
    this->Q = new T[this->Size];
}

template<class T>
void Queue<T>::Enqueue(T x){
    if(this->rear == this->Size - 1){
        cout<<"Queue is full!"<<endl;
    } else{
        this->rear++;
        this->Q[this->rear] = x;
    }
}

template<class T>
T Queue<T>::Dequeue(){
    T x;
    if(this->fr == this->rear){
        cout<<"Queue is Empty!"<<endl;
    } else{
        this->fr++;
        x = this->Q[this->fr];
    }
    return x;
}

template<class T>
bool Queue<T>::isEmpty(){
    return this->fr == this->rear;
}

template<class T>
bool Queue<T>::isFull(){
    return this->rear == this->Size - 1;
}

template<class T>
void Queue<T>::Display(){
    for(int i = this->fr + 1; i <= rear; i++){
        cout <<this->Q[i] << " ";
    }
    cout <<"\n";
}

template<class T>
Queue<T>::~Queue()
{
    delete []Q;
}


#endif // IMPLEMENTATION_H_INCLUDED
