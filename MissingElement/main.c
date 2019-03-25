#include <stdio.h>
#include <stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

void Append(struct Array *arr, int val){
    arr->A[arr->length] = val;
    arr->length++;
}

void Display(struct Array *arr){
    printf("Elements are:\n");
    int i = 0;
    for(i = 0; i < arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

int missingElement(struct Array *arr){
    int n = arr->A[arr->length - 1];
    int total = (n)*(n + 1)/2;
    int sum = 0;
    int i = 0;
    for(i = 0; i < arr->length; i++){
        sum += arr->A[i];
    }
    return total - sum;
}

int missingElementFrom(struct Array *arr){
    int diff = arr->A[0];
    int i = 0;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i] - i != diff){
            return diff + i;
        }
    }
    return -1;
}

void missingMultipleElement(struct Array *arr){
    int diff = arr->A[0];
    int i = 0;
    printf("Start:\n");
    for(i = 0; i < arr->length; i++){
        if(arr->A[i] - i != diff){
            while(arr->A[i] - i > diff){
                printf("Missing Elements %d\n", i + diff);
                diff++;
            }
        }
    }
}

void missingMultipleElements(struct Array *arr, int low, int high){
    struct Array H;
    H.size = 20;
    H.A = (int *)malloc((high + 1) * sizeof(int));
    H.length = 0;
    int i = 0;
    for(i = 0; i <= high; i++){
        Append(&H, 0);
    }
    //Display(&H);

    printf("Start:\n");
    for(i = 0; i < arr->length; i++){
        H.A[arr->A[i]] = 1;
    }
    //Display(&H);

    for(i = low; i < high; i++){
        if(H.A[i] != 1){
            printf("Missing Element is %d\n", i);
        }
    }
}


int main()
{
    printf("Missing Elements:\n");
    struct Array arr;
    arr.size = 20;
    arr.length = 0;
    arr.A = (int *)malloc(9 * sizeof(int));
    int i = 0;
    for(i = 1; i < 10; i++){
        if(i != 7)
            Append(&arr, i);
    }
    Display(&arr);
    printf("Missing element: %d\n", missingElement(&arr));
    printf("Missing element: %d\n", missingElementFrom(&arr));

    struct Array arr2;
    arr2.size = 20;
    arr2.length = 0;
    arr2.A = (int *)malloc(9 * sizeof(int));
    for(i = 1; i < 10; i++){
        if(i + 7 != 12 && i + 7 != 13)
            Append(&arr2, i + 7);
    }
    Display(&arr2);
    printf("Missing element: %d\n", missingElementFrom(&arr2));
    missingMultipleElement(&arr2);
    missingMultipleElements(&arr2, 8, 16);

    struct Array arr3;
    arr3.size = 20;
    arr3.length = 0;
    arr3.A = (int *)malloc(9 * sizeof(int));
    Append(&arr3, 7);
    Append(&arr3, 5);
    Append(&arr3, 9);
    Display(&arr3);
    missingMultipleElements(&arr3, 5, 9);
    return 0;
}
