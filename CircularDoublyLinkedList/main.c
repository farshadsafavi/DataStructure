#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

int Length(struct Node *c){
    int len = 0;
    if(c == NULL) return 0;
    do{
        c = c->next;
        len++;
    }while(c != first);
    return len;
}

void Display(struct Node *c){
    if(c == NULL) return;
    do{
        printf("%d ", c->data);
        c = c->next;
    }while(c != first);
    printf("\n");
}

void DisplayFromLast(struct Node *c){
    if(c == NULL) return;
    do{
        printf("%d ", c->data);
        c = c->prev;
    }while(c != last);
    printf("\n");
}

void Insert(struct Node *c, int index, int x){
    int i = 0;
    if(index < 0 || index > Length(c)){
        return;
    }
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        if(first == NULL){
            t->prev = t;
            t->next = t;
            first = t;
            last = t;
        } else{
            t->next = first;
            first->prev = t;
            t->prev = last;
            last->next = t;
            first = t;
        }
    } else{
        for(i = 0; i <index - 1; i++){
            c = c->next;
        }
        t->prev = c;
        t->next = c->next;
        if(c->next == first) last = t;
        c->next->prev = t;
        c->next = t;
    }
}

int Delete(struct Node *c, int index){
    int i = 0;
    int x;
    if(index <= 0 || index > Length(c)){
        return -1;
    }

    if(index == 1){

        x = first->data;
        if(first->next == first){
            free(first);
            first = NULL;
            last = NULL;
        } else{
            c->prev->next = c->next;
            c->next->prev = c->prev;
            first=first->next;
            free(c);
        }

    } else{
        for(i = 0; i <index - 1; i++){
            c = c->next;
        }
        x = c->data;
        c->prev->next = c->next;
        c->next->prev = c->prev;
        if(c->next == first) last = c->prev;
        free(c);
    }
    return x;
}

int MiddleNode(struct Node *c){
    struct Node *p, *q;
    p = c;
    q = c->next;
    if(p == q) {
        printf("The middle is: %d\n", p->data);
        return p->data;
    }
    while(q != last){
        p = p->next;
        q = q->next;
        q = q != last ? q->next : last;
    }
    printf("The middle is: %d\n", p->data);
    return p->data;
}


int main()
{
    printf("Circular Doubly LinkedList!\n");
    Insert(first, 0, 1);
    Display(first);
    Insert(first, 0, 2);
    Display(first);
    MiddleNode(first);
    Insert(first, 0, 3);
    Display(first);
    MiddleNode(first);

    Insert(first, 1, 8);
    Display(first);
    MiddleNode(first);

    Insert(first, 2, 0);
    Display(first);
    MiddleNode(first);

    Insert(first, 5, 10);
    Display(first);
    MiddleNode(first);

    Insert(first, 5, 11);
    Display(first);
    MiddleNode(first);
    /*
    Delete(first, 6);
    Display(first);
    Delete(first, 2);
    Display(first);
    Delete(first, 3);
    Display(first);
    Delete(first, 3);
    Display(first);
    Delete(first, 1);
    Display(first);
    Delete(first, 1);
    Display(first);*/
    return 0;
}
