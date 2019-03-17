#include <stdio.h>
#include <stdlib.h>
struct array{
    int A[20];
    int length;
    int size;
};

void Display(struct array *arr){
    int i = 0;
    for(i = 0; i < arr->length; i++){
        printf("%d\n", arr->A[i]);
    }
    printf("--------\n");
}

struct array* merge(struct array *arr1, struct array *arr2){
    int i = 0, j = 0, k = 0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));

    printf("Start merge!\n");
    while(i < arr1->length && j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        } else{
            arr3->A[k++] = arr2->A[j++];
        }
    }
    while(i < arr1->length){
        printf("i = %d and j = %d\n", i, j);
        arr3->A[k++] = arr1->A[i++];
    }

    while(j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        arr3->A[k++] = arr2->A[j++];
    }
    arr3->length = arr2->length + arr1->length;
    return arr3;
};

int main()
{
    printf("create an object of an array:\n");
    struct array arr1 = {{3, 8, 16, 20, 22, 25}, 5, 20};
    Display(&arr1);
    struct array arr2 = {{4, 10, 12, 22, 23}, 5, 20};
    Display(&arr2);
    struct array *arr3;
    arr3 = merge(&arr1, &arr2);
    Display(arr3);

    return 0;
}
