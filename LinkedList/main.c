#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct Node{
    int value;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    int i;
    struct Node *newNode, *last;
    if(n > 0){
        first = (struct Node*)malloc(sizeof(struct Node));
        first->value = A[0];
        first->next = NULL;
        last = first;
        for(i = 1; i < n; i++){
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = A[i];
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }
    }
}

void Display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void DisplayR(struct Node *p){
    if (p == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", p->value);
    DisplayR(p->next);
}

void DisplayRPost(struct Node *p){
    if (p == NULL) {
        return;
    }
    DisplayRPost(p->next);
    printf("%d ", p->value);
}

int Count(struct Node *p){
    if(p == NULL){
        return 0;
    }
    return Count(p->next) + 1;
}

int Count2(struct Node *p){
    int total = 0;
    while(p){
        total ++;
        p = p->next;
    }
    return total;
}

int Sum(struct Node *p){
    if(p == NULL){
        return 0;
    }
    return Sum(p->next) + p->value;
}

int Sum2(struct Node *p){
    int total = 0;
    while(p){
        total += p->value;
        p = p->next;
    }
    return total;
}

int Max(struct Node *p){
    int max = INT_MIN;
    while(p){
        if(p->value > max){
            max = p->value;
        }
        p = p->next;
    }
    return max;
}

int Max2(struct Node *p){
    Max3(p, INT_MIN);
}
int Max3(struct Node *p,int max){
    if(p == NULL){
        return max;
    }
    return Max3(p->next,p->value >  max?p->value:max);
}

int MaxR(struct Node *p){
    if(p == 0)
        return INT_MIN;
    if(MaxR(p->next) < p->value){
        return p->value;
    } else{
       return MaxR(p->next);
    }
}

int main()
{
    printf("Linked List:\n");
    int A[] = {3, 5, 7, 32, 15, 17 , 18 , 19};
    create(A, 8);
    Display(first);
    DisplayR(first);
    DisplayRPost(first);
    printf("\n");
    printf("count is: %d\n", Count(first));
    printf("count is: %d\n", Count2(first));
    printf("Sum is: %d\n", Sum(first));
    printf("Sum is: %d\n", Sum2(first));
    printf("Max is: %d\n", Max(first));
    printf("Max is: %d\n", Max2(first));
    printf("Max recursive is: %d\n", MaxR(first));
    return 0;
    return 0;
}
