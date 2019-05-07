#include <iostream>
#include<Queue.h>

using namespace std;

int main()
{
    cout << "Queue using stack:" << endl;
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    if(Q.isEmpty()){
        cout <<"empty!" << endl;
    } else{
        cout <<"size:" << Q.Size() << endl;
    }
    cout << Q.Dequeue() << endl;
    cout << Q.Dequeue() << endl;
    cout << Q.Dequeue() << endl;
    cout << Q.Dequeue() << endl;
    return 0;
}
