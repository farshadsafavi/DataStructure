#include <stdio.h>
#include <stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

struct Array2{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nElements are:\n");
    for(i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Display2(struct Array2 arr){
    int i;
    printf("\nElements are:\n");
    for(i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array2 *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array2 *arr, int index, int x){
    int i;
    if(index >= 0 && index <= arr->length){
        for(i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    /*
    printf("Create an array!\n");
    struct Array arr;
    printf("Enter size of an array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter all elements: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
        arr.length = i+1;
    }
    Display(arr);
    */
    struct Array2 arr2 = {{6,7,8,9,10},20, 5};
    Display2(arr2);

    Append(&arr2,11);
    Display2(arr2);

    Insert(&arr2, 2, 5);
    Display2(arr2);

    return 0;
}
