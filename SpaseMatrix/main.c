#include <stdio.h>
#include <stdlib.h>
struct Sparse{
    int row;
    int col;
    int num;
    struct Element *e;
};

struct Element{
    int i;
    int j;
    int val;
};

void create(struct Sparse *s){
    printf("Please Enter dimensions(row and col): ");
    scanf("%d %d", &s->row, &s->col);
    printf("Please Enter number of elements:");
    scanf("%d", &s->num);
    s->e = (struct Element *)malloc(s->num*sizeof(struct Element));
    int i = 0;
    printf("Please Enter elements' value:\n");
    for(i = 0; i < s->num; i++){
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].val);
    }
}

void Display(struct Sparse *s){
    printf("Elements are:\n");
    int i = 0;
    int j = 0;
    int num = 0;
    for(i = 0; i < s->row; i++){
        for(j = 0; j < s->col; j++){
            if(s->e[num].i == i && s->e[num].j == j){
                printf("%d ", s->e[num].val);
                num++;
            }else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("Sparse Matrix:\n");
    struct Sparse s;
    create(&s);
    Display(&s);
    return 0;
}
