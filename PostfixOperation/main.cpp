#include <iostream>
#include <stack>
#include<math.h>
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

string Postfix(string s){
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
    return res;
}

int evaluate(char oper, int first,int second){
    int res;
    switch(oper) {
        case ('+'):
            res = first + second;
            break;
        case ('-'):
            res = first - second;;
            break;
        case ('*'):
            res = first * second;;
            break;
        case ('/'):
            res = first / second;;
            break;
        case ('^'):
            res = pow(first, second);
            break;
    }
    return res;
}


int EvaluatePostfix(string s){
    int res = 0;
    stack<int> stk;
    int i = 0;
    while(i < s.length()){
        if(!isOperator(s[i])){
            stk.push(s[i] - '0');
            i++;
        } else{
            int second = stk.top();
            stk.pop();
            int first = stk.top();
            stk.pop();
            res = evaluate(s[i], first, second);
            stk.push(res);
            i++;
        }
    }
    return res;
}



int main()
{
    cout << "Postfix Operation" << endl;
    string s  = "((a+b)*c)-(d^(e^f))";
    string pf = Postfix(s);
    s  = "((1+2)*3)-(2^(2^2))";
    pf = Postfix(s);
    cout <<EvaluatePostfix(pf)<< endl;
    return 0;
}
