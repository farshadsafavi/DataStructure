#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED

template<class T>
Arrays<T>::Arrays()
{
    this->A = new T[10];
    this->Size = 10;
    this->length = 0;
}

template<class T>
Arrays<T>::Arrays(int Size)
{
    this->A = new T[Size];
    this->Size = Size;
    this->length = 0;
}

template<class T>
void Arrays<T>::Display(){
    for(int i = 0; i < this->length; i++){
        cout << this->A[i] <<" ";
    }
    cout <<endl;
}

template<class T>
void Arrays<T>::Insert(int index, T value){
    if(index >= 0 && index <= this->length){
        for(int i = this->length - 1; i >= index; i--){
            this->A[i + 1] = this->A[i];
        }
        this->A[index] = value;
        this->length++;
    }
}

template<class T>
T Arrays<T>::Delete(int index){
    T res;
    if(index >= 0 && index < this->length){
        res = this->A[index];
        for(int i = index; i < this->length - 1; i++){
            this->A[i] = this->A[i+1];
        }
        this->length--;
    }
    return res;
}

template<class T>
Arrays<T>::~Arrays()
{
    cout <<"De-construct Array!"<<endl;
    delete []A;
}


#endif // IMPLEMENTATION_H_INCLUDED
