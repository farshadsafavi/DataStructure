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
    printf("Please Enter elements' value:(i, j, val)\n");
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

struct Sparse* Add(struct Sparse *s1, struct Sparse *s2){
    struct Sparse *res;
    int count = 0;
    int i = 0, j = 0;
    if(s1->row != s2->row && s1->col != s2->col)
        return NULL;

    res=(struct Sparse *)malloc(sizeof(struct Sparse));
    res->row = s1->row;
    res->col = s1->col;
    int num = s1->num + s2->num;
    res->e = (struct Element*)malloc(num*sizeof(struct Element));
    while(i < s1->num && j < s2->num){
        if(s1->e[i].i < s2->e[j].i){
            res->e[count++] = s1->e[i++];
        } else if(s1->e[i].i > s2->e[j].i){
            res->e[count++] = s2->e[j++];
        } else{
            if(s1->e[i].j < s2->e[j].j){
                res->e[count++] = s1->e[i++];
            } else if(s1->e[i].j > s2->e[j].j){
                res->e[count++] = s2->e[j++];
            } else{
                res->e[count]=s1->e[i];
                res->e[count++].val = s1->e[i++].val + s2->e[j++].val;
            }
        }

    }

    while(i < s1->num ){
        res->e[count++] = s1->e[i++];
    }
    while(j < s2->num ){
        res->e[count++] = s2->e[j++];
    }
    res->num = count;
    return res;

}

int main()
{
    printf("Sparse Matrix:\n");
    struct Sparse s1,s2,*s3;

    create(&s1);
    printf("First Matrix\n");
    Display(&s1);

    create(&s2);
    printf("Second Matrix\n");
    Display(&s2);

    s3=Add(&s1,&s2);

    printf("Sum Matrix\n");
    Display(s3);
    return 0;
}
