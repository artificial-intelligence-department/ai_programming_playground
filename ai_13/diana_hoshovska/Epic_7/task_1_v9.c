#include <stdio.h>
#include <math.h>

int main(){
    double a=0.7, b=0.05, x=0.43;
    double R, S;

    R=x*x*(x+1)/(b-(sin(x-a)*sin(x-a)));
    S=sqrt(x*b/a)+abs(pow(cos(x+b), 3));

    printf("%lf\n", R);
    printf("%lf\n", S);

    return 0;
}