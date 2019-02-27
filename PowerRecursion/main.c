#include <stdio.h>
#include <stdlib.h>
int pow(int m, int n){
    if (n == 0){
        return 1;
    }
    return pow(m, n - 1)*m;
}

int pow2(int m, int n){
    if (n == 0){
        return 1;
    }
    if (n%2 == 0){
        return pow2(m*m, n/2);
    }
    return m*pow2(m*m, (n - 1)/2);
}

int pow3(int m, int n){
    int i = 0;
    int p;
    if (n%2 == 0){
        p = 1;
        for(i = 0; i < n/2; i++){
            p *= m*m;
        }
    } else{
        p = m;
        for(i = 0; i < (n-1)/2; i++){
            p *= m*m;
        }
    }
    return p;
}

int main()
{
    printf("Power Functions:\n");
    printf("%d\n", pow(2, 10));
    printf("%d\n", pow2(3, 2));
    printf("%d\n", pow3(2, 10));
    return 0;
}
