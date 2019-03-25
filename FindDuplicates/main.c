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

void findDuplicatesSortedArray(struct Array *arr){
    int i = 0;
    int num = -1;
    for(i = 0; i < arr->length - 1; i++){
        if(arr->A[i] == arr->A[i+1] && num != arr->A[i]){
            printf("The duplicate is: %d\n", arr->A[i]);
            num = arr->A[i];
        }
    }
}

void countDuplicatesSortedArray(struct Array *arr){
    int i = 0;
    int j;
    for(i = 0; i < arr->length - 1; i++){
        int count = 1;
        j = i+1;
        while(arr->A[i] == arr->A[j]){
            count++;
            j++;
        }
        i = j - 1;
        if(count > 1)
            printf("The count %d is: %d\n", arr->A[i], count);
    }
}

int main()
{
    printf("Find Duplicates!\n");
    struct Array arr;
    arr.size = 20;
    arr.length = 15;
    int i = 0;
    for(i = 0; i < arr.length; i++){
        if(i > 5 && i < 8){
            arr.A[i] = 5;
        } else if(i >= 12 && i < 14){
            arr.A[i] = 12;
        } else{
            arr.A[i] = i;
        }
    }
    Display(&arr);
    findDuplicatesSortedArray(&arr);
    countDuplicatesSortedArray(&arr);
    return 0;
}
