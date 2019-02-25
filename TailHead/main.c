#include <stdio.h>
#include <stdlib.h>
void fun1(int n){
    if(n > 0){
        printf("%d\n", n);
        fun1(n - 1);
    }
}

void fun2(int n){
    if(n > 0){
        fun2(n - 1);
        printf("%d\n", n);
    }
}

int main()
{
    printf("Tail and Head Recursion:\n");
    fun1(10);
    printf("-----\n");
    fun2(10);
    return 0;
}
