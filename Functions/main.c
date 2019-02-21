#include <stdio.h>
#include <stdlib.h>
int add(int x, int y){
    return x + y;
}

void swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap1(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    printf("Hello world!\n");
    int x = 10;
    int b = 13;
    int c = add(x, b);
    printf("%d + %d = %d\n", x, b, c);

    b = 10;
    x = 20;
    swap(b, x);
    printf("b is %d and x is %d\n", b, x);
    swap1(&b, &x);
    printf("b is %d and x is %d\n", b, x);

    return 0;
}
