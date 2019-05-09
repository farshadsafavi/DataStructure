#include <iostream>
#include<stack>
using namespace std;

int findMin(stack<int> &s1, stack<int> &s2, int top){
    int minimum = s1.top();
    while(!s1.empty()){
        s2.push(s1.top());
        if(minimum > s1.top() && minimum ){
            minimum = s1.top();
        }
        s1.pop();
    }
    return minimum;
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

    stack<int> s2;
    while(){
        cout << findMin(s1, s2) <<endl;
    }

    cout << s2.top() <<endl;
    return 0;
}
