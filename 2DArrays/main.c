#include <stdio.h>
#include <stdlib.h>
void printArray(int row, int col, int a[row][col] ){
    int i =0,j = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void printArray2(int row, int col, int* a[col] ){
    int i =0,j = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void printArray3(int row, int col, int** a ){
    int i =0,j = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("2D Array in stack:\n");
    int a[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 6, 9, 12}};
    printArray(3, 4, a);

    printf("2D Array of pointers to heap:\n");
    int *B[3];
    B[0] = (int *) malloc(4*sizeof(int));
    B[1] = (int *) malloc(4*sizeof(int));
    B[2] = (int *) malloc(4*sizeof(int));
    int i =0,j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            B[i][j] = i + j;
        }
    }
    printArray2(3, 4, B);

    printf("2D Array of pointers in heap to heap:\n");
    int **C;
    C = (int *) malloc(3*sizeof(int));
    C[0] = (int *) malloc(4*sizeof(int));
    C[1] = (int *) malloc(4*sizeof(int));
    C[2] = (int *) malloc(4*sizeof(int));
    i =0,j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            if(i == j)
                C[i][j] = 1;
            else
                C[i][j] = 0;
        }
    }
    printArray3(3, 4, C);
    return 0;
}


