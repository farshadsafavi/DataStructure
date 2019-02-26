#include <stdio.h>
#include <stdlib.h>
int treeRecursion(int n){
    if(n > 0){
        printf("%d\n", n);
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}
int main()
{
    printf("Tree Recursion!\n");
    treeRecursion(3);
    return 0;
}
