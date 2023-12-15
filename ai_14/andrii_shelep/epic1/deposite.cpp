#include <cmath>
#include <stdio.h>

int main()
{
    char name[100];
    double principal , rate , amount; 
    int years , period;

    printf ("Enter your name:");
    scanf ("%s", &name);
    
    printf ("Enter the principal amount:");
    scanf ("%lf", &principal);
    
    printf ("Enter the rate of interest (in percentage):");
    scanf ("%lf", &rate);
    
    printf ("Enter the number of years:");
    scanf ("%d", &years);
    
    printf ("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):");
    scanf ("%d", &period);

    rate = rate/100;

    amount = principal*pow((1+rate/period),period*years);

    printf("Hello, %s!\nThe compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", name, principal, rate * 100, period, years, amount);
    return 0;
}