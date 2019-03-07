#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Increase Array Size:\n");
    int *p, *q;
    p = (int *) malloc(5*sizeof(int));
    int i = 0;
    for (i = 0; i < 5; i++){
        p[i] = i;
    }
    q = (int*) malloc(10*sizeof(int));
    for (i = 0; i < 5; i++){
        q[i] = p[i];
    }
    free(p);
    for (i = 0; i < 10; i++){
        printf("%d\n", q[i]);
    }
    return 0;
}
