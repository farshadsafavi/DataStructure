#include <iostream>
#include<Queue.h>

using namespace std;

int main()
{
    cout << "Queue Array" << endl;
    Queue<int> q(8);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    Queue<string> q2(10);

    q2.Enqueue("Farshad");
    q2.Enqueue("Toktam");
    q2.Enqueue("Armin");
    cout << q2.Dequeue() << endl;
    cout << q2.Dequeue() << endl;
    cout << q2.Dequeue() << endl;
    cout << q2.Dequeue() << endl;
    cout << q2.Dequeue() << endl;
    q2.Enqueue("Farshad");
    q2.Enqueue("Toktam");
    q2.Enqueue("Armin");
    q2.Enqueue("Navid");
    q2.Enqueue("Nana");
    q2.Enqueue("Farideh");
    q2.Display();
    return 0;
}
