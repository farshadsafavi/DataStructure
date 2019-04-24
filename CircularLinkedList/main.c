#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head;

void create(int A[], int n){
    // create the head node
    struct Node *last, *t;
    int i = 0;
    for(i = 0; i < n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        if(i == 0){
            head = t;
            head->next = head;
            last = head;
        } else{
            t->next = head;
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *c){
    do{
        printf("%d ", c->data);
        c = c->next;
    }while(c != head);
    printf("\n");
}

void DisplayRec(struct Node *c){
    static int flag = 0;
    if(c != head || flag == 0){
        flag = 1;
        printf("%d ", c->data);
        Display(c->next);
    }
    flag = 0;
}

int Length(struct Node *c){
    if(c == NULL) return 0;
    int l = 0;
    do{
        c = c->next;
        l++;
    }while(c != head);
    return l;

}

void Insert(struct Node *c, int pos,int x){
    struct Node *t;
    int i = 0;
    if(pos < 0 || pos > Length(c)){
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(pos == 0){
        if(head == NULL){
            head = t;
            head->next = head;
        } else{
            while(c->next != head) c = c->next;
            c->next = t;
            t->next = head;
            head = t;
        }
    } else{
        for(i = 0; i < pos - 1; i++){
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
}


int Delete(struct Node *c, int index){
    int i = 0;
    int x;
    if(index <= 0 || index > Length(c) ){
        return -1;
    }
    if(index == 1){
        if(head->next == head){
            free(head);
            head = NULL;
        } else{
            while(c->next != head){
                c = c->next;
            }
            c->next = head->next;
            x = head->data;
            free(head);
            head = c->next;
        }
    } else{
        for(i = 0; i < index - 2; i++){
            c = c->next;
        }
        struct Node *q = c->next;
        c->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}

int isLoop(struct Node *c){
    struct Node *q, *p;
    p = q = c;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next:NULL;
    }while(p != q && p && q);

    if(p == q){
        return 1;
    } else{
        return 0;
    }
}

int main()
{
    printf("Circular LinkedList:\n");
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(head, 4, 1);
    Display(head);
    Insert(head, 5, 2);
    Display(head);
    Insert(head, 6, 3);
    Display(head);
    Insert(head, 3, 4);
    Display(head);
    Insert(head, 0, 5);
    Display(head);
    DisplayRec(head);
    printf("length is: %d\n", Length(head));
    printf("Deleted %d\n", Delete(head,1));
    Display(head);
    printf("Deleted %d\n",Delete(head,3));
    Display(head);
    printf("Deleted %d\n",Delete(head,2));
    Display(head);
    printf("Deleted %d\n",Delete(head,6));
    Display(head);
    printf("Deleted %d\n",Delete(head,4));
    Display(head);

    printf("length is: %d\n", Length(head));
    printf("is Loop: %d\n", isLoop(head));
    return 0;
}
