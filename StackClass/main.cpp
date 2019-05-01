#include <iostream>
#include<Stack.h>
using namespace std;

int main()
{
    cout << "Stack Class:" << endl;
    Stack<char> stk(5);

    stk.Push('a');
    stk.Push('b');
    stk.Push('c');
    stk.Push('d');
    stk.Push('e');
    stk.Push('f');

    stk.Display();
    if (stk.isFull())cout <<"Stack is Full!" << endl;
    cout<<"pop " <<stk.Pop()<<endl;
    cout<<"The top is " <<stk.StackTop()<<endl;
    cout<<stk.Peek(1)<<endl;
    return 0;
}
