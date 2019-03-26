#include <stdio.h>
#include <stdlib.h>
struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array *arr){
    int i = 0;
    printf("Elements are:\n");
    for(i = 0; i < arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void findPairs(struct Array *arr, int k){
    int i = 0;
    int j = 0;
    for(i = 0; i < arr->length - 1; i++){
        for(j = i + 1; j < arr->length; j++){
            if(arr->A[i] + arr->A[j] == k){
                printf("The pairs that equal to %d is %d and %d\n", k, arr->A[i], arr->A[j]);
            }
        }
    }
}

void findPairsHashmap(struct Array *arr, int k, int high){
    struct Array H;
    H.size = high + 1;
    H.length = high + 1;
    int i = 0;
    for(i = 0; i < H.length; i++){
        H.A[i] = 0;
    }
    for(i = 0; i < arr->length; i++){
        if(H.A[k - arr->A[i]] == 1){
            printf("The pairs that equal to %d is %d and %d\n", k, arr->A[i], k - arr->A[i]);
        }
        H.A[arr->A[i]] = 1;
    }
}

void findPairsSorted(struct Array *arr, int k){
    int i = 0;
    int j = arr->length - 1;
    while(i < j){
        if(arr->A[i] + arr->A[j] == k){
            printf("The pairs that equal to %d is %d and %d\n", k, arr->A[i], k - arr->A[i]);
            i++;
            j--;
        } else if (arr->A[i] + arr->A[j] < k){
            i++;
        } else{
            j--;
        }
    }
}

void findMinMax(struct Array *arr){
    if(arr->length == 0) return;
    int min = arr->A[0];
    int max = arr->A[0];
    int i = 0;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i] < min){
            min = arr->A[i];
        } else if(arr->A[i] > max){
            max = arr->A[i];
        }
    }
    printf("Min = %d and Max = %d\n", min, max);
}


int main()
{
    printf("Finding pair of elements sum equals to K:\n");
    struct Array arr;
    arr.size = 10;
    arr.length = 10;
    arr.A[0] = 6;
    arr.A[1] = 3;
    arr.A[2] = 8;
    arr.A[3] = 10;
    arr.A[4] = 16;
    arr.A[5] = 7;
    arr.A[6] = 5;
    arr.A[7] = 2;
    arr.A[8] = 9;
    arr.A[9] = 14;
    Display(&arr);
    findPairs(&arr, 10);
    findPairsHashmap(&arr, 10, 16);

    struct Array arr2;
    arr2.size = 10;
    arr2.length = 10;
    arr2.A[0] = 1;
    arr2.A[1] = 3;
    arr2.A[2] = 4;
    arr2.A[3] = 5;
    arr2.A[4] = 6;
    arr2.A[5] = 8;
    arr2.A[6] = 9;
    arr2.A[7] = 10;
    arr2.A[8] = 12;
    arr2.A[9] = 14;
    Display(&arr);
    findPairsSorted(&arr, 10);
    findMinMax(&arr);
    return 0;
}
