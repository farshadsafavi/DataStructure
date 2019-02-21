#include <stdio.h>
#include <stdlib.h>

// pass array as argument
void printArray(int A[], int length){
    int i = 0;
    for (i = 0; i < length; i++){

        printf("%d ", A[i]);
    }
    printf("\n");
}

// argument as array
void changeArrayValue(int A[], int length){
    int i = 0;
    for (i = 0; i < length; i++){
        A[i] = 100 + i;
    }
}
// Call array by address
void changeArrayValue2(int* A, int length){
    int i = 0;
    for (i = 0; i < length; i++){
        A[i] = 200 + i;
    }
}

// Return pointer
int * pointerReturn(int length){
    int *p;
    p = (int *)malloc(length * sizeof(int));
    int i = 0;
    for (i = 0; i < length; i++){
        p[i] = 300 + i;
    }
    return p;
}

int main()
{
    printf("Arrays as pointer:\n");
    int A[] = {1, 2, 3, 4, 5};
    printArray(A, 5);
    // modify array
    changeArrayValue(A, 5);
    printArray(A, 5);
    //modify array
    changeArrayValue2(A, 5);
    printArray(A, 5);

    int *B;
    B = pointerReturn(5);
    printArray(B, 5);

    return 0;
}
