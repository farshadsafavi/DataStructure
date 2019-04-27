#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct Node{
    int value;
    struct Node *next;
}*first = NULL, *last = NULL, *second = NULL;

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

void create2(int A[],int n)
{
     int i;
     struct Node *t,*last;
     second=(struct Node *)malloc(sizeof(struct Node));
     second->value=A[0];
     second->next=NULL;
     last=second;

     for(i=1;i<n;i++)
     {
         t=(struct Node*)malloc(sizeof(struct Node));
         t->value=A[i];
         t->next=NULL;
         last->next=t;
         last=t;
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

struct Node* Search(struct Node *c, int key){
    struct Node *p;
    while(c != NULL){
        printf("%d \n", c->value);
        if(c->value == key){
            p->next = c->next;
            c->next = first;
            first = c;
            return c;
        }
        p = c;
        c = c->next;
    }
    printf("\n");
    return NULL;
}

struct Node* SearchRec(struct Node *c, int key){
    if(c == NULL)
        return NULL;
    if(c->value == key){
        return c;
    }
    return SearchRec(c->next, key);
}

void Insert(struct Node *c, int pos, int val){
    int i;

    if(pos < 0 || pos > Count(first))
        return;

    struct Node* n = (struct Node *)malloc(sizeof(struct Node));
    n->value = val;
    if(pos == 0){
        n->next = first;
        first = n;
    } else{
        for(i = 0; i < pos - 1; i++){
            c = c->next;
        }
        n->next = c->next;
        c->next = n;
    }

}


void InsertLast(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->value = val;
    n->next = NULL;
    if(first == NULL){
        first = last = n;
    }
    else{
        last->next = n;
        last = n;
    }
}

void InsertInSortedList(int val){
    struct Node* c = first;
    struct Node* p;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->value = val;
    n->next = NULL;
    if(first == NULL){
        first = n;
    } else if(val < first->value){
        n ->next = first;
        first = n;
    } else{
        while(c != NULL && val > c->value){
            p = c;
            c = c->next;
        }
        p->next = n;
        n->next = c;
    }
}

int Delete(struct Node *c, int pos){
    int x;
    if(pos < 0 || pos > Count(first) || c == NULL)
        return -1;
    if(pos == 0){
        c = first;
        x = first->value;
        first = first->next;
        free(c);
        return x;
    } else{
        int i = 0;
        struct Node *p;
        for(i = 0; i < pos && c; i++){
            p = c;
            c = c->next;
        }
        x = c->value;
        p->next = c->next;
        free(c);
        return x;
    }
}

bool isSorted(struct Node *c){
    int temp = INT_MIN;
    while(c){
        if(temp > c->value){
            return false;
        }
        temp = c->value;
        c = c->next;
    }
    return true;
}

void RemoveDuplicate(struct Node *c){
    struct Node *p;
    p = c;
    c = c->next;
    while(c != NULL){
        if(p->value == c->value){
            p->next = c->next;
            free(c);
            c = p->next;
        } else{
            p = c;
            c = c->next;
        }
    }
}

void Reverse(struct Node *c){
    struct Node *p, *pp;
    c = first;
    p = NULL;
    pp = NULL;
    while(c != NULL){
       pp = p;
       p = c;
       c = c->next;
       p->next = pp;
    }
    first = p;
}

void ReverseRec(struct Node *p, struct Node *c){
    if(c != NULL){
        ReverseRec(c, c->next);
        c->next = p;
    } else{
        first = p;
    }
}

struct Node* Merge(struct Node *p,struct Node *q){
    struct Node *third, *last;
    if(q->value < p->value){
        third = last = q;
        q = q->next;
        third->next = NULL;
    } else{
        third = last = p;
        p = p ->next;
        third->next = NULL;
    }
    while(p && q){
        if(q->value < p->value){
            last->next = q;
            last = last->next;
            q = q->next;
            last->next = NULL;
        } else{
            last->next = p;
            last = last->next;
            p = p->next;
            last->next = NULL;
        }
    }
    if(q) last->next = q;
    if(p) last->next = p;

    return third;
}

int isLoop(struct Node *f){
    struct Node *p = f;
    struct Node *q = f;

    do{
        p = p->next;
        q = q->next;
        q = q ? q->next:q;
    }while(p != q && p && q);

    return p == q ? true:false;
}

int FindMiddle(struct Node *c){
    struct Node *p, *q;
    p = q = c;
    q = q->next;
    q = q ? q->next: NULL;
    while(q != NULL){
        p = p->next;
        q = q->next;
        q = q ? q->next: NULL;
    }
    printf("The middle number is: %d\n", p->value);
    return p->value;
}

int FindMiddle2(struct Node *c){
    struct Node *p, *q;
    p = q = c;
    while(q != NULL){
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    printf("The middle number is: %d\n", p->value);
    return p->value;
}

int main()
{
    /*
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
    struct Node* n = Search(first, 17);struct Node *third
    if(n != NULL)
        printf("The result is %d\n", n->value);
    else
        printf("Not found\n");

    Display(first);
    struct Node* n2 = SearchRec(first, 22);
    if(n2 != NULL)
        printf("The result is %d\n", n2->value);
    else
        printf("Not found\n");

    Insert(first, 0, 10);
    Display(first);
    Insert(first, 1, 13);
    Display(first);
    Insert(first, 2, 2);
    Display(first);
    Insert(first, 0, 8);
    Display(first);

    InsertLast(3);
    Display(first);
    InsertLast(5);
    Display(first);
    InsertLast(10);
    Display(first);

    printf("Linked List:\n");
    int A[] = {3, 5, 7, 32, 15, 17 , 18 , 19};
    create(A, 8);
    Display(first);
    if(isSorted(first)){
        printf("It is sorted!\n");
    } else{
        printf("It is NOT sorted!\n");
    }

    Delete(first, 0);
    Display(first);
    Delete(first, 3);
    Display(first);
    Delete(first, 3);
    Display(first);
    Delete(first, 0);
    Display(first);
    Delete(first, 0);
    Display(first);
    Delete(first, 0);
    Display(first);

    InsertInSortedList(4);
    Display(first);
    InsertInSortedList(2);
    Display(first);
    InsertInSortedList(17);
    Display(first);
    InsertInSortedList(17);
    Display(first);
    InsertInSortedList(17);
    Display(first);
    InsertInSortedList(0);
    Display(first);
    InsertInSortedList(3);
    Display(first);
    InsertInSortedList(3);
    Display(first);
    InsertInSortedList(3);
    Display(first);
    InsertInSortedList(3);
    Display(first);
    InsertInSortedList(5);
    Display(first);
    if(isSorted(first)){
        printf("It is sorted!\n");
    } else{
        printf("It is NOT sorted!\n");
    }
    RemoveDuplicate(first);
    Display(first);
    Reverse(first);
    Display(first);
    ReverseRec(NULL, first);
    Display(first);
    */
    int A[]={10,20,30,40,50};
    int B[]={15,18,25,30,55};
    create(A,5);
    create2(B,5);
    Display(first);
    FindMiddle2(first);
    Display(second);
    FindMiddle2(second);

    struct Node *third = Merge(first, second);
    Display(third);
    FindMiddle2(third);
    /*
    struct Node *t1,*t2;

    int A[]={10,20,30,40,50};
    create(A,5);

    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    printf("it is loop %d\n",isLoop(first));*/

    return 0;
}
