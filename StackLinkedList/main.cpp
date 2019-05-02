#include <iostream>
#include<Stack.h>

using namespace std;
bool PranthesisBalance(string s){
    Stack<char> stk;
    for(char i:s){
        if(i == '('){
            stk.Push(i);
        }
        if(i == ')'){
            if(stk.isEmpty()) {
                return false;
            }
            stk.Pop();
        }
    }
    return stk.isEmpty();
}

bool BraketsBalance(string s){
    Stack<char> stk;
    for(char i:s){
        if(i == '(' || i == '[' || i == '{'){
            stk.Push(i);
        }
        if(i == ')'){
            if(stk.isEmpty() || stk.Pop() != '(') {
                return false;
            }
        }
        else if(i == '}'){
            if(stk.isEmpty() || stk.Pop() != '{') {
                return false;
            }
        }
        else if(i == ']'){
            if(stk.isEmpty() || stk.Pop() != '[') {
                return false;
            }
        }
    }
    return stk.isEmpty();
}

int main()
{
    cout << "Stack using LinkedList!" << endl;
    Stack<int> stk;
    stk.Push(11);
    stk.Push(12);
    stk.Push(13);
    stk.Push(14);

    stk.Display();
    cout << stk.Peek(3)<< endl;
    cout << stk.Pop()<< endl;
    cout << stk.Pop()<< endl;
    cout << stk.Pop()<< endl;
    cout << stk.Pop()<< endl;
    cout << stk.isEmpty()<< endl;

    string s = "(I([]{}{{(())}} am learner, therefore I am))";

    if (BraketsBalance(s))
        cout <<"Balanced!\n";
    else
        cout <<"Not Balanced!\n";

    return 0;
}


