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

int Delete(struct Array2 *arr, int index){
    int i;
    int x;
    if(index >= 0 && index <= arr->length){
        x = arr->A[index];
        for(i = index; i < arr->length; i++){
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}
void swap(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

int search(struct Array2 *arr, int x){
    int i;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i] == x){
            swap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}

int getArray(struct Array2 *arr, int i){
    if(i >= 0 && i < arr->length){
        return arr->A[i];
    }
    return -1;
}

void setArray(struct Array2 *arr, int i, int x){
    if(i >= 0 && i < arr->length){
        arr->A[i] = x;
    }
}

int MaxArray(struct Array2 *arr){
    int i = 0;
    if (arr->length > 0){
        int max = arr->A[0];
        for(i = 1; i < arr->length; i++){
            if(arr->A[i] > max){
                max = arr->A[i];
            }
        }
        return max;
    }
    return -1;
}

int MinArray(struct Array2 *arr){
    int i = 0;
    if (arr->length > 0){
        int min = arr->A[0];
        for(i = 1; i < arr->length; i++){
            if(arr->A[i] < min){
                min = arr->A[i];
            }
        }
        return min;
    }
    return -1;
}

int SumArray(struct Array2 *arr){
    int i = 0;
    int total = 0;
    for(i = 0; i < arr->length; i++){
        total += arr->A[i];
    }
    return total;
}

float AvgArray(struct Array2 *arr){
    return (float)SumArray(arr)/arr->length;
}

int Bsearch(struct Array2 *arr, int x){
    int start = 0;
    int end = arr->length - 1;
    while( start <= end){
        int i = (start + end) / 2;
        printf("%d", i);
        if(arr->A[i] < x){
            start = i + 1;
        }else if (arr->A[i] > x){
            end = i - 1;
        }else if (arr->A[i] == x){
            return i;
        }
    }
    return -1;
}

int Bsearch_r(struct Array2 *arr, int start, int end, int x){
    int i = (start + end) / 2;
    if( start <= end){
        if(arr->A[i] < x){
            return Bsearch_r(arr, i + 1, end, x);
        }else if (arr->A[i] > x){
            return Bsearch_r(arr, start, i - 1,  x);
        }else if (arr->A[i] == x){
            return i;
        }
    }
    return -1;
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

    printf("\ndeleted: %d\n", Delete(&arr2, 6));
    Display2(arr2);

    printf("\nfind 5 at index: %d\n", search(&arr2, 5));
    Display2(arr2);
    printf("\nfind 5 at index: %d\n", search(&arr2, 5));
    Display2(arr2);
    printf("\nfind 5 at index: %d\n", search(&arr2, 5));
    Display2(arr2);

    int x = 5;
    int y = 4;
    swap(&x, &y);
    printf("\nx = %d and y = %d\n", x, y);

    struct Array2 arr3 = {{6,7,8,9,10},20, 5};
    printf("\nfind 6 at index: %d\n", Bsearch(&arr3, 6));
    printf("\nfind 7 at index: %d\n", Bsearch(&arr3, 7));
    printf("\nfind 8 at index: %d\n", Bsearch(&arr3, 8));
    printf("\nfind 9 at index: %d\n", Bsearch(&arr3, 9));
    printf("\nfind 10 at index: %d\n", Bsearch(&arr3, 10));
    printf("\nfind 11 at index: %d\n", Bsearch(&arr3, 11));
    printf("\nfind 5 at index: %d\n", Bsearch(&arr3, 5));
    Display2(arr3);

    printf("\nfind 6 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 6));
    printf("\nfind 7 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 7));
    printf("\nfind 8 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 8));
    printf("\nfind 9 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 9));
    printf("\nfind 10 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 10));
    printf("\nfind 11 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 11));
    printf("\nfind 5 at index: %d\n", Bsearch_r(&arr3, 0, arr3.length, 5));

    printf("Get index 3: %d\n", getArray(&arr3, 3));
    printf("Get index 0: %d\n", getArray(&arr3, 0));
    printf("Get index 9: %d\n", getArray(&arr3, 9));

    printf("Set index 0 to value 15!");
    setArray(&arr3, 0, 15);
    Display2(arr3);

    printf("Max value in the array is: %d\n", MaxArray(&arr3));
    printf("Max value in the array is: %d\n", MaxArray(&arr2));

    printf("Min value in the array is: %d\n", MinArray(&arr3));
    printf("Min value in the array is: %d\n", MinArray(&arr2));

    printf("Sum value in the array is: %d\n", SumArray(&arr3));
    printf("Sum value in the array is: %d\n", SumArray(&arr2));

    printf("Average value in the array is: %lf\n", AvgArray(&arr3));
    printf("Average value in the array is: %lf\n", AvgArray(&arr2));
    return 0;
}
