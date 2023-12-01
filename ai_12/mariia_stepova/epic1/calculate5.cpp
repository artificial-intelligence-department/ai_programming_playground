#include <stdio.h>
#include <math.h>

int main() 
{
    char name[50];
    double principal, rate, total, interest;
    int years, n;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the number of times interest is compounded per year(e.g., 1 for annually, 4 for quarterly, 12 for monthly): : ");
    scanf("%d", &n);

    // Convert the rate from percentage to decimal
    rate = rate / 100;

    // Calculate the total amount
    total = principal * pow(1 + rate / n, years * n);

    // Calculate the compound interest
    interest = total - principal;

    printf("Hello %s\n",name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, years, interest);
    printf ("Total is: %.2f", total);

    return 0;
}