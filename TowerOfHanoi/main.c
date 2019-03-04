#include <stdio.h>
#include <stdlib.h>
void towerHanoi(int n, char A, char B, char C){
    int static cnt = 0;
    if(n > 0){
        towerHanoi(n - 1, A, C, B);
        printf("%d - from %c to %c\n",++cnt,  A, C);
        towerHanoi(n - 1, B, A, C);
    }
}
int main()
{
    printf("Tower of Hanoi\n");
    towerHanoi(3, 'A', 'B', 'C');
    return 0;
}
