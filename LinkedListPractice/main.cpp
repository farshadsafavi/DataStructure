#include <iostream>
#include<LinkedList.h>

using namespace std;

int main()
{
    cout << "LinkedList Practice!" << endl;
    LinkedList l;
    cout <<"count: " <<l.Count() <<endl;
    l.Insert(0, 2);
    l.Display();
    l.Insert(1, 4);
    l.Display();
    l.Insert(2, 5);
    l.Display();
    l.Insert(3, 6);
    l.Display();
    l.Insert(4, 7);
    l.Display();
    l.Reverse();
    l.Display();
    l.ReverseRec();
    l.Display();
    return 0;
}
