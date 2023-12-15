#include <stdio.h>
#include <math.h>
int main()
{
    float a = 1000, b = 0.0001, numerator=0, denominator=0, rez=0;
    numerator = pow(a+b,3)-(pow(a,3)+3*pow(a,2)*b);
    denominator = 3*a*pow(b,2)+pow(b,3);
    rez = numerator/denominator;
    printf("%lf", rez);
}