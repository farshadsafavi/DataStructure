#include <stdio.h>
#include <stdlib.h>
int fib(int n){
    int t0 = 0;
    int t1 = 1;
    if(n <= 1) return n;
    int i = 0;
    int s;
    for(i = 2; i <=n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib2(int n){
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int fib3(int n){
    int mem[10];
    int i = 0;
    for(i = 0; i < 10; i++){
        mem[i] = -1;
    }
    if(n <= 1) {
        mem[n] = n;
        return n;
    }
    if(mem[n - 1] == -1){
        mem[n - 1] = fib3(n - 1);
    }
    if(mem[n - 2] == -1){
        mem[n - 2] = fib3(n - 2);
    }
    return mem[n - 1] + mem[n - 2];
}

int main()
{
    printf("Fibonacci:\n");
    printf("%d\n", fib(10));
    printf("%d\n", fib2(10));
    printf("%d\n", fib3(10));
    return 0;
}
