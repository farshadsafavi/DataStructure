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
    static double sign = 1;
    static double res;
    if (n == 0){
        p = x;
        res += x;
    }
    if (n > 0) {
        sin2(x, n - 1);
        p = p*x*x;
        f = f*(2*n + 1)*(2*n);
        sign *= -1;
        //printf("%lf\n", sign);
        res += (p/f)*sign;
    }
    return res;
}

double sin3(double x,double n){
    static double res = 1;
    if(n == 1) return res*x;
    double s = x*x/((2*n - 1)*(2*n - 2))*res;
    res = 1 - s;
    return sin3(x, n - 1);
}


int main()
{
    printf("Sin Taylor Series!\n");
    double pi = 3.14159265359;

 //   printf("%lf\n", sin1(pi/6,15));
 //   printf("%lf\n", sin1(pi,15));
 //   printf("%lf\n", sin1(pi/2,15));

  //  printf("%lf\n", sin2(pi/6,15));
  //  printf("%lf\n", sin2(pi,15));
  //  printf("%lf\n", sin2(pi/2,15));

  printf("%lf\n", sin3(pi/2,15));
 //   printf("%lf\n", sin1(pi,15));
 //   printf("%lf\n", sin1(pi/2,15));
    return 0;
}
