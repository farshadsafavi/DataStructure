#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i = 0;
    printf("Array Initialization:\n");
    int A[5] = {1, 2, 3, 4, 5};
    printf("Traverse array A:\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", A[i]);
    }
    int B[5] = {2, 3, 4};
    printf("Traverse array B:\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", i[B]);
    }
    int C[5] = {0};
    printf("Traverse array C:\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", *(C + i));
    }
    int D[5] = {0};
    printf("Traverse addresses of array D:\n");
    for(i = 0; i < 5; i++){
        printf("%u\n", &D[i]);
    }
    int E[] = {1,2 ,3 ,4 ,5 ,6 , 7, 8};
    printf("Traverse array E:\n");
    for(i = 0; i < 8; i++){
        printf("%d\n", E[i]);
    }
    return 0;
}
