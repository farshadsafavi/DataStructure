#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
}*head = NULL;

void Create(struct Node *c, int m){
    int i = 0;
    for(i = 0; i < m; i++){
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        printf("Please enter coef and exp:");
        scanf("%d %d", &n->coef, &n->exp);
        n->next = NULL;
        Insert(head, n);
    }
}

void Insert(struct Node *c, struct Node *n){
    struct Node *p = c;
    if (head==NULL) head = n;
    else{
        while(c != NULL && c->exp < n->exp){
            p = c;
            c = c->next;
        }

        if(p == c){
            if(c->exp == n->exp) c->coef = c->coef + n->coef;
            else{
                n->next = head;
                head = n;
            }
        } else{
            if(c && c->exp == n->exp) c->coef = c->coef + n->coef;
            else if(p && p->exp == n->exp) p->coef = p->coef + n->coef;
            else{
                p->next = n;
                n->next = c;
            }
        }

    }
}

float Evaluation(struct Node *c, int x){
    float sum = 0;
    while(c != NULL){
        sum += (float)c->coef*pow(x, c->exp);
        c = c->next;
    }
    return sum;
}

void Display(struct Node *c){
    while(c != NULL){
        printf("%dX%d + ", c->coef, c->exp);
        c = c->next;
    }
    printf("\n");
}

int main()
{
    printf("Polynomial:\n");
    printf("Please enter number of terms:");
    int m;
    scanf("%d", &m);
    Create(head, m);
    Display(head);
    printf("Evaluation x = 2 is %f\n", Evaluation(head, 2));
    return 0;
}
