#include <iostream>
#include<QueueArray.h>
#include<QueueLinkedList.h>
using namespace std;

int main()
{
    cout << "Double Ended Queue:" << endl;
    /*
    QueueArray Q;
    Q.AddLast(10);
    Q.AddLast(20);
    Q.Display();
    Q.RemoveFirst();
    Q.RemoveLast();
    Q.Display();
    Q.AddLast(10);
    Q.AddLast(20);
    Q.AddLast(30);
    Q.AddLast(40);
    Q.Display();
    cout <<"Remove first" << endl;
    Q.RemoveFirst();
    Q.Display();
    cout <<"Remove last" << endl;
    Q.RemoveLast();
    Q.Display();
    cout <<"Remove first" << endl;
    Q.RemoveFirst();
    Q.Display();
    cout <<"Remove last" << endl;
    Q.RemoveLast();
    Q.Display();
    Q.AddFirst(10);
    Q.AddFirst(20);
    Q.AddFirst(30);
    Q.AddLast(40);
    Q.AddLast(50);
    Q.AddLast(60);
    */
    QueueLinkedList Q;
    Q.AddLast(10);
    Q.AddLast(20);
    Q.AddFirst(0);
    Q.AddLast(30);
    Q.Display();

    Q.RemoveFirst();
    Q.Display();
    Q.RemoveFirst();
    Q.Display();
    Q.RemoveFirst();
    Q.Display();
    Q.RemoveFirst();
    Q.Display();

    Q.AddLast(10);
    Q.AddLast(20);
    Q.AddLast(30);
    Q.AddLast(40);
    Q.Display();
    Q.RemoveLast();
    Q.Display();
    Q.RemoveLast();
    Q.Display();
    Q.RemoveLast();
    Q.Display();

    Q.AddLast(10);
    Q.AddLast(20);
    Q.AddFirst(0);
    Q.AddLast(30);
    Q.Display();
    cout <<"Remove first" << endl;
    Q.RemoveFirst();
    Q.Display();
    cout <<"Remove last" << endl;
    Q.RemoveLast();
    Q.Display();
    cout <<"Remove first" << endl;
    Q.RemoveFirst();
    Q.Display();
    cout <<"Remove last" << endl;
    Q.RemoveLast();
    Q.Display();
    Q.AddFirst(3);
    Q.AddFirst(2);
    Q.AddFirst(1);
    Q.AddLast(40);
    Q.AddLast(50);
    Q.AddLast(60);

    Q.Display();
    return 0;
}
