#include <stdio.h>
#include <stdlib.h>
int fun(int n){
    if(n > 100)
        return (n - 10);
    return fun(fun(n + 11));
}

int main()
{
    printf("Nested Recursion\n");
    printf("%d\n", fun(95));
    return 0;
}
