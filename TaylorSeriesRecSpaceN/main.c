#include <stdio.h>
#include <stdlib.h>
double e(int x, int n){
    static double s;
    if (n == 0) return s;
    s = 1+x*s/n;
    return e(x, n-1);
}

double e2(int x, int n){
    static double s = 1;
    int i = n;
    for(i = n; i >0; i--){
        s = 1+x*s/i;
    }
    return s;
}

double e3(int x, int n){
    static double p = 1;
    static double f = 1;
    static double s = 1;
    if(n > 0){
        e3(x, n - 1);
        f *= n;
        p *= x;
        s += p/f;
    }
    return s;
}

double e4(int x, int n){
    double p = 1;
    double f = 1;
    double s = 1;
    int i = 0;
    for(i = 1; i <= n ; i++){
        f *= i;
        p *= x;
        s += p/f;
    }
    return s;
}

int main()
{
    printf("Taylor series more efficient!\n");
    printf("%lf\n",e(1, 10) );
    printf("%lf\n",e2(1, 10) );
    printf("%lf\n",e3(1, 10) );
    printf("%lf\n",e4(1, 10) );
    return 0;
}
