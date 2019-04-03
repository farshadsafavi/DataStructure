#include <stdio.h>
#include <stdlib.h>
struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x){
    if(i >= j)
        m->A[(i*(i - 1)/2) + j - 1] = x;
}

int Get(struct Matrix *m, int i, int j){
    if(i >= j)
        return m->A[(i*(i - 1)/2) + j - 1];
    else
        return 0;
}

void Display(struct Matrix m){
    int i, j;
    for(i = 1; i <= m.n; i++){
        for(j = 1; j<= m.n; j++){
            if(i >= j)
                printf("%d ", m.A[(i*(i - 1)/2) + j - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Set2(struct Matrix *m,int i,int j,int x)
{
    if(i>=j)
        m->A[m->n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}

int Get2(struct Matrix m, int i, int j){
    if(i >= j)
        return m.A[m.n*(j -1) - ((j - 2)*(j - 1)/2) + (i - j)];
    else
        return 0;
}

void Display2(struct Matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i>=j)
                printf("%d ",m.A[m.n*(j-1) - (j-2)*(j-1)/2+i-j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    printf("Row major mapping and column major mapping:\n");
    struct Matrix m;
    printf("Enter the dimensions of triangular matrix:");
    scanf("%d", &m.n);
    m.A = (int *)malloc((m.n*(m.n + 1)/2)*sizeof(int));

    int i, j, x;
    printf("Enter all elements:\n");
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++){
            scanf("%d", &x);
            Set2(&m, i, j, x);
        }
    }
    printf("\n\n");
    Display2(m);

    return 0;
}
