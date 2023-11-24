#include <cmath>
#include <cstdio>
#include <math.h>
#include <iostream>

int main()
{
    char name[50];
    double amount, rate;
    int years, period;
    double a, q;
    printf("Enter your name:");
    scanf("%s", name);
    printf("Enter your principal amount:");
    scanf("%lf", &amount);
    printf("Enter rate of interest(in percentage):");
    scanf("%lf", &rate);
    printf("Enter the number of years:");
    scanf("%d", &years);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quaterly, 12  for monthly):");
    scanf("%d", &period);

    rate /= (double) 100;
    a=amount*pow(1+(rate/period), period*years);
    q =a - amount;
    printf("Hello %s", name);
    printf("\nThe compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate * 100, period, years, q);
    printf("The total is: %.2f", a);
    return 0;
    
}