#include <stdio.h>
#include <stdlib.h>
struct array{
    int *A;
    int size;
    int length;
};

void Display(struct array *arr){
    printf("Elements are:\n");
    int i = 0;
    for(i = 0; i < arr->length; i++){
        printf("%d\n",arr->A[i]);
    }
}

void MergeArrays(struct array *arr1, struct array *arr2, struct array *arr3){
    int i = 0, j = 0, k = 0;
    printf("Merges:\n");
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            printf("i %d %d\n", i, arr1->length);
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i] > arr2->A[j]){
            printf("j %d %d\n", j, arr2->length);
            arr3->A[k++] = arr2->A[j++];
        } else{
            printf("j %d %d\n", j, arr2->length);
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        arr3->length++;
    }
    while(i < arr1->length){
        arr3->A[k++] = arr2->A[i++];
        arr3->length++;
    }
    while(j < arr2->length){
        arr3->A[k++] = arr2->A[j++];
        arr3->length++;
    }
}

struct array* MergeArrays2(struct array *arr1, struct array *arr2){
    int i = 0, j = 0, k = 0;
    struct array *arr3;
    arr3->A = (int *)malloc(20*sizeof(int));
    arr3->size = 20;
    arr3->length = 0;
    printf("Merges:\n");
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else if(arr1->A[i] > arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
        }else{
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        arr3->length++;
    }
    while(i < arr1->length){
        arr3->A[k++] = arr2->A[i++];
        arr3->length++;
    }
    while(j < arr2->length){
        arr3->A[k++] = arr2->A[j++];
        arr3->length++;
    }
    return arr3;
}



int main()
{
    printf("Merge two arrays\n");
    struct array arr1;
    arr1.A = (int *)malloc(20*sizeof(int));
    arr1.size = 20;
    arr1.length = 0;
    int i = 0;
    for(i = 0; i <= 5; i++){
        arr1.A[i] = i + 5;
        arr1.length++;
    }
    Display(&arr1);

    struct array arr2;
    arr2.A = (int *)malloc(20*sizeof(int));
    arr2.size = 20;
    arr2.length = 0;
    for(i = 0; i <= 7; i++){
        arr2.A[i] = i*3;
        arr2.length++;
    }
    Display(&arr2);

    struct array arr3;
    arr3.A = (int *)malloc(20*sizeof(int));
    arr3.size = 20;
    arr3.length = 0;
    MergeArrays(&arr1, &arr2, &arr3);
    Display(&arr3);

    struct array *arr4;
    arr4 = MergeArrays2(&arr1, &arr2);
    Display(arr4);

    return 0;
}
