#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    int sz;
    printf("Pleas enter the size:");
    scanf("%d", &sz);
    st->size  = sz;
    st->top = -1;
    st->s = (struct Stack *)malloc(sizeof(sz));
}

void Display(struct Stack *st){
    int i = 0;
    for(i = st->top; i >= 0; i--){
        printf("%d ", st->s[i]);
    }
    printf("\n", st->s[i]);
}

void Push(struct Stack *st, int x){
    if(st->top == st->size - 1){
        printf("Stack overflow\n");
    } else{
        st->top++;
        st->s[st->top] = x;
    }
}

int Pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack underflow!\n");
    } else{
        x = st->s[st->top--];
    }
    return x;
}

int Peek(struct Stack st, int pos){
    int x = -1;
    int Index = st.top - pos + 1;
    if(Index < 0){
        printf("Stack underflow!\n");
    } else{
        x = st.s[Index];
    }
    return x;
}

int isEmpty(struct Stack st){
    return (st.top == -1);
}

int isFull(struct Stack st){
    return(st.top == st.size - 1);
}

int stackTop(struct Stack st){
    if(!isEmpty(st)) return st.s[st.top];
    return -1;
}

int main()
{
    printf("Stack:\n");
    struct Stack st;
    create(&st);

    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);

    printf("Peek: %d\n", Peek(st, 2));
    Display(&st);
    return 0;
}
