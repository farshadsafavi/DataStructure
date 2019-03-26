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

void findDuplicatesUnsortedArray(struct Array *arr){
    int i = 0;
    int j = 0;
    int num = -1;
    for(i = 0; i < arr->length - 1; i++){
        int count = 1;
        if(arr->A[i] != -1){
            for(j = i + 1; j <arr->length; j++){
                if(arr->A[i] == arr->A[j]){
                    arr->A[j] = -1;
                    count++;
                }
            }
            if(count > 1)
                printf("The value %d is repeated %d times.\n", arr->A[i], count);
        }
    }
}

void findDuplicatesHashmap(struct Array *arr, int high){
    struct Array H;
    H.size = high;
    H.length = high;
    int i = 0;
    //initialize
    for(i = 0; i <= H.length; i++){
        H.A[i] = 0;
    }

    for(i = 0; i < arr->length; i++){
        H.A[arr->A[i]] += 1;
    }

    for(i = 0; i <= H.length; i++){
        if(H.A[i] > 1)
            printf("The value %d is repeated %d times.\n", i, H.A[i]);
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

    printf("Find duplicates in unsorted array!\n");
    struct Array arr2;
    arr2.size = 20;
    arr2.length = 10;
    arr2.A[0] = 8;
    arr2.A[1] = 3;
    arr2.A[2] = 6;
    arr2.A[3] = 4;
    arr2.A[4] = 6;
    arr2.A[5] = 5;
    arr2.A[6] = 6;
    arr2.A[7] = 8;
    arr2.A[8] = 2;
    arr2.A[9] = 7;
    Display(&arr);
    findDuplicatesUnsortedArray(&arr);
    Display(&arr2);
    findDuplicatesUnsortedArray(&arr2);
    arr2.size = 20;
    arr2.length = 13;
    arr2.A[0] = 8;
    arr2.A[1] = 3;
    arr2.A[2] = 6;
    arr2.A[3] = 4;
    arr2.A[4] = 6;
    arr2.A[5] = 5;
    arr2.A[6] = 6;
    arr2.A[7] = 8;
    arr2.A[8] = 2;
    arr2.A[9] = 7;
    arr2.A[10] = 7;
    arr2.A[11] = 7;
    arr2.A[12] = 7;
    Display(&arr2);
    findDuplicatesHashmap(&arr2, 8);
    return 0;
}
