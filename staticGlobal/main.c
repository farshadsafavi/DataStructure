#include <stdio.h>
#include <stdlib.h>
int fun1(int n){
    if(n > 0){
        return fun1(n - 1) + n;
    }
    return 0;
}

int fun2(int n){
    int static x = 0;
    if(n > 0){
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}

int y = 0;
int fun3(int n){
    if(n > 0){
        y++;
        return fun3(n - 1) + y;
    }
    return 0;
}

int main()
{
    printf("static and global variable in a recursion functions:\n");
    printf("%d\n",fun1(5) );

    printf("%d\n",fun2(5) );
    printf("%d\n",fun2(5) );

    printf("%d\n",fun3(5) );
    printf("%d\n",fun3(5) );
    return 0;
}
