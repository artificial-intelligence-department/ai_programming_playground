#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    char name [100];
    printf ("Enter your name: ");
    scanf("%99[^\n]",&name);

    double principal;
    printf ("Enter the principal amount: ");
    scanf ("%lf",&principal);

    double rate;
    printf ("Enter the rate of interest in percentage: ");
    scanf ("%lf",&rate);

    int years;
    printf ("Enter the number of years: ");
    scanf ("%d",&years);

    int period;
    printf ("Enter the number of times interest is compounded per year: ");
    scanf ("%d",&period);

    rate=rate/100;
    double result= principal*(1+rate/period);

    printf ("The total amount after entered years is ");
    printf("%.2f", result);
    return 0;

}