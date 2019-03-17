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

struct array* Union(struct array *arr1, struct array *arr2){
    int i = 0, j = 0, k = 0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    arr3->length = 0;
    printf("Start Union!\n");
    while(i < arr1->length && j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        } else if(arr1->A[i] > arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
        } else{
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        arr3->length++;
    }
    while(i < arr1->length){
        printf("i = %d and j = %d\n", i, j);
        arr3->A[k++] = arr1->A[i++];
        arr3->length++;
    }

    while(j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        arr3->A[k++] = arr2->A[j++];
        arr3->length++;
    }
    return arr3;
};

struct array* Intersection(struct array *arr1, struct array *arr2){
    int i = 0, j = 0, k = 0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    arr3->length = 0;
    printf("Start Intersection!\n");
    while(i < arr1->length && j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        if(arr1->A[i] == arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            k++;
        }
        i++;
        j++;
    }
    arr3->length = k;
    return arr3;
};

struct array* Difference(struct array *arr1, struct array *arr2){
    int i = 0, j = 0, k = 0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    arr3->length = 0;
    printf("Start Difference!\n");
    while(i < arr1->length && j < arr2->length){
        printf("i = %d and j = %d\n", i, j);
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        } else if(arr1->A[i] > arr2->A[j]){
            j++;
        } else{
            j++;
            i++;
        }
    }
    while(i < arr1->length){
        printf("i = %d and j = %d\n", i, j);
        arr3->A[k++] = arr1->A[i++];
    }
    arr3->length = k;
    return arr3;
};



int main()
{
    printf("create an object of an array:\n");
    struct array arr1 = {{3, 8, 16, 20, 22, 25}, 6, 20};
    Display(&arr1);
    struct array arr2 = {{3, 4, 10, 12, 22, 23}, 6, 20};
    Display(&arr2);
    struct array *arr3;
    arr3 = merge(&arr1, &arr2);
    Display(arr3);
    arr3 = Union(&arr1, &arr2);
    Display(arr3);
    arr3 = Intersection(&arr1, &arr2);
    Display(arr3);
    struct array arr4 = {{2, 6, 10, 15,  17, 18, 19, 25}, 8, 20};
    struct array arr5 = {{3, 6, 7, 15, 17, 20}, 6, 20};
    arr3 = Difference(&arr4, &arr5);
    Display(arr3);

    return 0;
}
