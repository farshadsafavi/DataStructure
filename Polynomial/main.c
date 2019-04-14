#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Term{
    int coef;
    int exp;
};

struct Poly{
    int num;
    struct Term *A;
};

void Create(struct Poly *p){
    printf("Enter number of terms:");
    scanf("%d", &p->num);
    p->A = (struct Term*)malloc(p->num*sizeof(struct Term));

    printf("Read all the terms(coef and exp):\n");
    int i = 0;
    for(i = 0; i < p->num;i++){
        scanf("%d %d", &p->A[i].coef, &p->A[i].exp);
    }
}

struct Poly* add(struct Poly *p1, struct Poly *p2){
    struct Poly* sum = (struct Poly*)malloc(sizeof(struct Poly));;
    sum->A = (struct Term*)malloc((p1->num + p2->num)*sizeof(struct Term));
    int i = 0, j = 0;
    int count = 0;
    while(i < p1->num && j < p2->num){
        if(p1->A[i].exp > p2->A[j].exp){
            sum->A[count++] = p1->A[i++];
        } else if(p1->A[i].exp < p2->A[j].exp){
            sum->A[count++] = p2->A[j++];
        } else{
            sum->A[count].exp = p1->A[i].exp;
            sum->A[count++].coef = p1->A[i++].coef + p2->A[j++].coef ;
        }
    }
    while(i < p1->num)
        sum->A[count++] = p1->A[i++];
    while(j < p2->num)
        sum->A[count++] = p2->A[j++];
    sum->num = count;

    return sum;
}


void Display(struct Poly p){
    int i = 0;
    for(i = 0; i < p.num;i++){
        printf("%dX%d+", p.A[i].coef, p.A[i].exp);
    }
    printf("\n");
}

int Evaluation(struct Poly p, int x){
    int i =0;
    int sum = 0;
    for(i = 0; i < p.num; i++){
        sum += p.A[i].coef*pow(x, p.A[i].exp);
    }
    return sum;
}

int main()
{
    printf("Polynomila!\n");
    struct Poly p1, p2, *p3;
    Create(&p1);
    printf("The first polynomial:\n");
    Display(p1);
    printf("Evaluate x = 2 is: %d\n", Evaluation(p1, 2));
    Create(&p2);
    printf("The Second polynomial:\n");
    Display(p2);
    printf("Evaluate x = 3 is: %d\n", Evaluation(p2, 3));

    printf("The Addition polynomial:\n");
    p3 = add(&p1, &p2);
    Display(*p3);
    return 0;
}
