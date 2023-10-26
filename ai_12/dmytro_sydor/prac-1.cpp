#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    char name[50];
    double principal, rate, totalAmount, compoundInterest;
    int years, n;
    printf ("Enter your name: ");
    scanf ("%s", name);

    printf ("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf ("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);

    printf ("Enter the number of years: ");
    scanf ("%d", &years);

    printf ("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d",&n);

    rate = rate/100;
    totalAmount = principal * pow(1+(rate/n),n*years);
    compoundInterest =  totalAmount - principal;

    printf("\nHello %s",name);
    printf("\nThe compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, years, compoundInterest);
    printf ("\nTotal is: %.2f", totalAmount); cout << endl;

    return 0;
}