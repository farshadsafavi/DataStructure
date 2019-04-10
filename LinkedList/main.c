#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    printf("Linked List:\n");
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    Display(first);
    DisplayR(first);
    DisplayRPost(first);
    return 0;
}
