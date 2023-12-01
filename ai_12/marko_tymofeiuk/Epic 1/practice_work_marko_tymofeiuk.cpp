#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    char name [50];
    int years, period;
    double principal, rate;

    printf ("Enter your name: ");
    scanf ("%s", &name);
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%i", &years);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%i", &period);
    printf(" \n");

    double truerate = rate/100;
    double income = principal * pow(1+(truerate/period), period*years) ;
    double display = income - principal;

    printf("Hello, %s!\n", name);
    if (years==1){
        printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %i times a year for %i year is: %.2lf \n", principal, rate, period, years, display);
        printf("The total amount after %i year is: %.2lf", years, income);
    } else {
        printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %i times a year for %i years is: %.2lf \n", principal, rate, period, years, display);
        printf("The total amount after %i years is: %.2lf", years, income);
    }

    return 0;
}