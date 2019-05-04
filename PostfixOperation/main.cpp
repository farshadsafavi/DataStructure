#include <iostream>
#include <stack>
using namespace std;
bool isOperator(char c){
    return (c == '+' ||
            c == '-' ||
            c == '*' ||
            c == '/' ||
            c == '^' ||
            c == '(' ||
            c == ')'
            );
}

int precedenceOut(char c){
    int res;
    switch(c) {
        case ('+'):
            res = 1;
            break;
        case ('-'):
            res = 1;
            break;
        case ('*'):
            res = 3;
            break;
        case ('/'):
            res = 3;
            break;
        case ('^'):
            res = 6;
            break;
        case ('('):
            res = 7;
            break;
        case (')'):
            res = 8;
            break;
    }
    return res;
}

int precedenceIn(char c){
    int res;
    switch(c) {
        case ('+'):
            res = 2;
            break;
        case ('-'):
            res = 2;
            break;
        case ('*') :
            res = 4;
            break;
        case ('/') :
            res = 4;
            break;
        case ('^'):
            res = 5;
            break;
        case ('(') :
            res = 0;
            break;
    }
    return res;
}


int main()
{
    cout << "Postfix Operation" << endl;
    string s = "((a+b)*c)-(d^(e^f))";
    stack<char> stk;
    string res = "";
    int i = 0;
    while(i < s.length()){
        if(!isOperator(s[i])){
            res += s[i];
            i++;
        } else{
            if(stk.empty() || precedenceIn(s[i]) < precedenceOut(s[i])){
                stk.push(s[i]);
                i++;
            }else{
                char temp = stk.top();
                stk.pop();
                if(temp != '(' && temp != ')' ){
                    res += temp;
                }
            }
        }
    }
    while(!stk.empty()){
        char temp = stk.top();
        stk.pop();
        if(temp != '(' && temp != ')' ){
            res += temp;
        }
    }
    cout <<res << endl;
    return 0;
}
