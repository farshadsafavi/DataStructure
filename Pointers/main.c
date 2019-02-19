#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Pointers:\n");
    int a = 10;
    int *p = &a;
    printf("%d\n", *p);

    p = (int *)malloc(5*sizeof(int));
    int i = 0;
    for(i = 0; i < 5; i++){
        p[i] = 100 + i;
    }
    for(i = 0; i < 5; i++){
        printf("%d\n", p[i]);
    }
    return 0;
}
