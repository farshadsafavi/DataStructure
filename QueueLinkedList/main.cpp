#include <iostream>
#include<Queue.h>
using namespace std;

int main()
{
    cout << "Queue LinkedList:" << endl;
    Queue q;
    q.Display();
    q.Enqueue(10);
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();
    for(int i = 0; i < 10; i++){
        q.Enqueue(i);
    }
    q.Display();
    for(int i = 0; i < 10; i++){
        cout <<q.Dequeue()<<endl;
    }
    q.Display();


    return 0;
}
