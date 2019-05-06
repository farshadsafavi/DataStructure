#include <iostream>
#include<CircularQueue.h>
using namespace std;

int main()
{
    cout << "Circular Queue:" << endl;
    CircularQueue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    cout << q.Dequeue()<< endl;
    q.Display();
    cout << q.Dequeue()<< endl;
    cout << q.Dequeue()<< endl;
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    return 0;
}
