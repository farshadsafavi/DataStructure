#include <stdio.h>
#include <stdlib.h>

int sum1(int n){
    if (n == 0)
        return 0;
    else
        return sum1(n - 1) + n;
}

int sum2(int n){
    return n*(n + 1)/2;
}

int sum3(int n){
    int sum = 0;
    int i = 0;
    for(i = 0; i <= n;i++){
       sum += i;
    }
    return sum;
}

int main()
{
    printf("Sum of natural numbers:\n");
    printf("%d\n", sum1(12));
    printf("%d\n", sum2(12));
    printf("%d\n", sum3(12));
    return 0;
}
