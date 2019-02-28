#include <stdio.h>
#include <stdlib.h>
double e(x, n){
    static double p = 1;
    static double f = 1;
    if(n == 0) return 1;
    double r = e(x, n-1);
    p *= x;
    f *= n;
    return r + p/f;
}

int main()
{
    printf("Taylor series!\n");
    printf("%lf\n", e(4, 15));
    return 0;
}
