#include <stdio.h>
#include <stdlib.h>
void print(int array[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d\n", array[i]);
    }
}
int main()
{
    printf("Static Array!\n");
    int A[10] = {1,2 ,3 , 4, 5, 7 ,7 ,8 ,8 ,8};
    print(A, 10);
    int *p;
    p = (int *)malloc(10*sizeof(int));
    int i = 0;
    for (i = 0; i < 10; i++){
        p[i] = i*2;
    }
    printf("-----------\n");
    printf("Dynamic Array!\n");
    for (i = 0; i < 10; i++){
        printf("%d\n", p[i]);
    }

    return 0;
}
