#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
}*head = NULL, *head2= NULL, *head3=NULL;

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

void Create2(struct Node *c, int m){
    int i = 0;
    for(i = 0; i < m; i++){
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        printf("Please enter coef and exp:");
        scanf("%d %d", &n->coef, &n->exp);
        n->next = NULL;
        Insert2(head2, n);
    }
}

void Insert2(struct Node *c, struct Node *n){
    struct Node *p = c;
    if (head2==NULL) head2 = n;
    else{
        while(c != NULL && c->exp < n->exp){
            p = c;
            c = c->next;
        }

        if(p == c){
            if(c->exp == n->exp) c->coef = c->coef + n->coef;
            else{
                n->next = head2;
                head2 = n;
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

void Addition(struct Node *c, struct Node *p, struct Node *q){
    struct Node *last = head3;
    while(p != NULL && c != NULL){
        //printf("%d %d ", p->exp, c->exp);

        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->next = NULL;
        if(c->exp == p->exp){
            n->coef = c->coef + p->coef;
            n->exp = c->exp;
            if(head3 == NULL){
                head3 = n;
                last = n;
            } else{
                last->next = n;
                last = n;
            }
            c = c->next;
            p = p->next;
        } else if(c->exp < p->exp){
            n->coef = c->coef;
            n->exp = c->exp;
            if(head3 == NULL){
                head3 = n;
                last = n;
            } else{
                last->next = n;
                last = n;
            }
            c = c->next;
        }else if(c->exp > p->exp){
            n->coef = p->coef;
            n->exp = p->exp;
            if(head3 == NULL){
                head3 = n;
                last = n;
            } else{
                last->next = n;
                last = n;
            }
            p = p->next;
        }
    }
    while(p != NULL){
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->next = NULL;
        n->coef = p->coef;
        n->exp = p->exp;
        if(head3 == NULL){
            head3 = n;
            last = n;
        } else{
            last->next = n;
            last = n;
        }
        p = p->next;
    }
    while(c != NULL){
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->next = NULL;
        n->coef = c->coef;
        n->exp = c->exp;
        if(head3 == NULL){
            head3 = n;
            last = n;
        } else{
            last->next = n;
            last = n;
        }
        c = c->next;
    }
}

int main()
{
    printf("Polynomial:\n");
    printf("Please enter number of terms:");
    int m;
    scanf("%d", &m);
    Create(head, m);
    Display(head);
    //printf("Evaluation x = 2 is %f\n", Evaluation(head, 2));
    printf("Please enter number of terms:");
    int m2;
    scanf("%d", &m2);
    Create2(head2, m2);
    Display(head2);

    Addition(head, head2, head3);
    printf("Final Result: \n");
    Display(head3);
    return 0;
}
