#include <iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> s1){
    stack<int> s2;
    while(!s1.empty()){
        int c = s1.top();
        s1.pop();
        while(!s2.empty() && s2.top() > c){
            int p = s2.top();
            s2.pop();
            s1.push(p);
        }
        s2.push(c);
    }
    while(!s2.empty()){
        int c = s2.top();
        s2.pop();
        s1.push(c);
    }
    return s1;
}

int main()
{
    cout << "Sort using stack:" << endl;
    stack<int> s1;
    s1.push(10);
    s1.push(6);
    s1.push(2);
    s1.push(0);
    s1.push(9);
    s1.push(11);

    s1 = sortStack(s1);
    while(!s1.empty()){
        int c = s1.top();
        s1.pop();
        cout <<c << " ";
    }
    cout << endl;
    return 0;
}
