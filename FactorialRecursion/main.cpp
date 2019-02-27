#include <iostream>

using namespace std;
int factorial(int n){
    if (n < 0) throw 101;
    if(n == 1) return 1;
    return factorial(n - 1)* n;
}

int factorial2(int n){
    if (n < 0) throw 102;
    int f = 1;
    if(n == 1) return 1;
    for(int i = 1; i <= n; i++){
        f *= i;
    }
    return f;
}

int main()
{
    cout << "Factorial:" << endl;
    try{
        factorial(-1);
    }catch(int e){
        cout <<"The negative number:" << e << endl;
    }

    try{
        cout <<factorial(5) << endl;
    }catch(int e){
        cout <<"The negative number:" << e << endl;
    }

    try{
        factorial(-1);
    }catch(int e){
        cout <<"The negative number:" << e << endl;
    }

    try{
        cout <<factorial2(5) << endl;
    }catch(int e){
        cout <<"The negative number:" << e << endl;
    }
    return 0;
}
