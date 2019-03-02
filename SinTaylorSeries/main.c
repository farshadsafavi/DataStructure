#include <stdio.h>
#include <stdlib.h>
double sin1(double x,double n){
    double p = x;
    double f = 1;
    double sign = 1;
    double res;
    int i;
    for(i = 1; i <= n; i++){
        res += (p/f)*sign;
        p = p * x * x;
        f = f*2*i*(2*i + 1);
        sign = sign*-1;
    }

    return res;
}

double sin2(double x,double n){
    static double p;
    static double f = 1;
    double sign = 1;
    static double res;
    if (n > 0){
        sin2(x, n - 1);
        f *= 2*n*(2*n + 1);
        p *= x * x;

        sign = sign * -1;
    }
    return res;
}

int main()
{
    printf("Sin Taylor Series!\n");
    double pi = 3.14159265359;
    /*
    printf("%lf\n", sin1(pi/6,15));
    printf("%lf\n", sin1(pi,15));
    printf("%lf\n", sin1(pi/2,15));*/

    printf("%lf\n", sin2(pi/6,15));
    return 0;
}
