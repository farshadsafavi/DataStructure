#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arrays!\n");
    int A[5] = {10, 22, -32, 75, -12};
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%d\n", A[i]);
    }
    return 0;
}
