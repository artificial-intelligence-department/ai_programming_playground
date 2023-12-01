#include <cmath>
#include <cstdio>
#include <math.h>
#include <iostream>

int main()
{
    char name[50];
    double principal, rate, total, e;
    int years, period;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your principal: ");
    scanf("%lf", &principal);
    printf("Enter rate: ");
    scanf("%lf", &rate);
    printf("Enter years: ");
    scanf("%d", &years);
    printf("Enter period: ");
    scanf("%d", &period);

    rate =  rate / 100;
    total = principal*pow(1+(rate/period), period*years);
    e = total - principal;
    printf("Hello, %s \n", name );
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, e);
    printf("The total is: %.2f", total);

    return 0;
}
