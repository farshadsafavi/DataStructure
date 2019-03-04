#include <stdio.h>
#include <stdlib.h>
int factoriel(int n){
    int total =  1;
    if(n <= 1) return 1;
    int i = 0;
    for(i = 1; i <= n; i++){
        total *= i;
    }
    return total;
}


int comb(int n, int r){
    int num = factoriel(n);
    int den = factoriel(n - r) * factoriel(r);
    return num/den;
}

int comb2(int n, int r){
    if(r == 0 || r==n ) return 1;
    return comb2(n - 1, r - 1) + comb2(n - 1, r);
}

int main()
{
    printf("Combination\n");
    printf("%d\n", comb(4, 2));
    printf("%d\n", comb2(4, 2));
    return 0;
}
