#include <stdio.h>
#include <stdlib.h>
struct Element{
    int value;
    int col;
    struct Element *next;
};

void create(struct Element *A[], int m, int n){
    int i =0, j = 0;
    for(i = 0; i < m; i++){
        A[i] = (struct Element*)malloc(sizeof(struct Element));
        A[i]->next = NULL;
    }

    struct Element *last;
    int v;
    printf("Please enter %dx%d matrix:\n", m, n);
    for(i = 0; i < m; i++){
        last = A[i];
        for(j = 0; j < n; j++){
            scanf("%d",&v);
            if(v != 0){
                struct Element * new_e = (struct Element*)malloc(sizeof(struct Element));
                new_e->col = j;
                new_e->value = v;
                new_e->next = NULL;
                last->next = new_e;
                last = new_e;
            }
        }
    }
    printf("\n");
}

void Display(struct Element *A[], int m, int n){
    int i, j;
    struct Element *last;
    for(i = 0; i < m; i++){
        last = A[i]->next;
        for(j = 0; j < n; j++){
            if(last!= NULL && last->col == j){
                printf("%d ", last->value);
                last = last->next;
            } else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void Add(struct Element *A[], struct Element *B[],struct Element *C[], int m, int n){
    int i = 0, j = 0;
    for(i = 0; i < m; i++){
        C[i] = (struct Element *)malloc(sizeof(struct Element));
        C[i]->next = NULL;
    }
    struct Element *lastA, *lastB, *lastC;
    for(i = 0; i < m; i++){
        lastA = A[i]->next;
        lastB = B[i]->next;
        lastC = C[i];
        for(j = 0; j < n; j++){
            if(lastA && lastB && lastA->col == j && lastB->col == j){
                struct Element *new_e = (struct Element *)malloc(sizeof(struct Element));
                new_e->col = j;
                new_e->next = NULL;
                new_e->value = lastA->value + lastB->value;
                lastA = lastA->next;
                lastB = lastB->next;
                lastC->next = new_e;
                lastC = new_e;
            } else if(lastA && lastA->col == j){
                struct Element *new_e = (struct Element *)malloc(sizeof(struct Element));
                new_e->col = j;
                new_e->next = NULL;
                new_e->value = lastA->value;
                lastA = lastA->next;
                lastC->next = new_e;
                lastC = new_e;
            } else if(lastB && lastB->col == j){
                struct Element *new_e = (struct Element *)malloc(sizeof(struct Element));
                new_e->col = j;
                new_e->next = NULL;
                new_e->value = lastB->value;
                lastB = lastB->next;
                lastC->next = new_e;
                lastC = new_e;
            }
        }
    }

}

int main()
{
    printf("Sparse matrix LinkedList:\n");
    printf("Please enter matrix dimensions(mxn):");
    int m, n;
    scanf("%d %d",&m, &n);
    printf("%d %d\n", m, n);
    struct Element *A[m];
    create(A, m, n);
    Display(A, m, n);
    struct Element *B[m];
    create(B, m, n);
    Display(B, m, n);
    struct Element *C[m];
    Add(A,B,C, m,n);
    Display(C, m, n);
    return 0;
}
