#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}*first = NULL;

void Create(int A[], int n){
    int i = 0;
    struct Node *last;
    for(i = 0; i < n; i++){
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        if(i == 0){
            t->next = NULL;
            t->prev = NULL;
            t->data = A[i];
            first = t;
            last = t;
        } else{
            t->next = NULL;
            t->prev = last;
            t->data = A[i];
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *c){
    while(c != NULL){
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}

int Length(struct Node *c){
    int len = 0;
    while(c != NULL){
        len++;
        c = c->next;
    }
    printf("Length is: %d\n", len);
    return len;
}

void Insert(struct Node *c, int index, int x){
    int i = 0;
    if(index < 0 || index > Length(c))
        return;
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = first;
        t->prev = NULL;
        if(first != NULL)
            first->prev = t;
        first = t;
    } else{
        for(i = 0; i < index - 1; i++){
            c = c->next;
        }
        t->prev = c;
        t->next = c->next;
        if(c->next != NULL){
            c->next->prev = t;
        }
        c->next = t;
    }
}

int main()
{
    printf("Doubly LinkedList!\n");
    /*
    int A[] = {10, 20 , 30 , 40, 50};
    Create(A, 5);
    Display(first);
    Length(first);*/
    Insert(first, 0, 0);
    Insert(first, 1, 1);
    Insert(first, 2, 2);
    Insert(first, 3, 2);
    Insert(first, 4, 2);
    Display(first);

    return 0;
}
