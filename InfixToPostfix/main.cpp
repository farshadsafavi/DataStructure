#include <iostream>
#include<stack>
using namespace std;
bool isOperator(char c){
    return c == '+' ||
           c == '-' ||
           c == '*' ||
           c == '/';
}

int Precedence(char oper){
    if(oper == '+' || oper == '-'){
        return 1;
    }
    if(oper == '*' || oper == '/'){
        return 2;
    }
    return 0;
}


int main()
{
    cout << "Convert infix to prefix:" << endl;
    stack<char> stk;
    string res= "";
    string s = "a+b*c-d/e";
    int i = 0;
    while(i < s.length()){
        if(!isOperator(s[i])){
            res += s[i++];
        } else{
            if(stk.empty() || Precedence(stk.top()) < Precedence(s[i])){
                stk.push(s[i++]);
            } else{
                res += stk.top();
                stk.pop();
            }
        }
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    cout << res << endl;

    return 0;
}
