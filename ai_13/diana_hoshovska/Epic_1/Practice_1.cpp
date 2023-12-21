#include <cstdio>
#include <cmath>

int main()
{
    int years, number;
    float principal, rate, compoundInterest;
    char name[20];

    printf("Enter your name: \n");
    scanf("%s", &name);

    printf("Enter the principal amount: \n");
    scanf("%f", &principal);

    printf("Enter the rate of interest: \n");
    scanf("%f", &rate);
    rate = rate/100;

    printf("Enter the number of years: \n");
    scanf("%i", &years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): \n");
    scanf("%i", &number);
    compoundInterest = principal * pow((1 + (rate/number)), number * years);

    printf("Hello, %s!", name);

    printf(" The compound interest for a principal of %.2f at a rate of %.2f%% compounded %i times a year for %i years is: %.2f\n", principal, rate * 100, number, years, compoundInterest - principal);
    printf("The total amount after %i years is: %.2f", years, compoundInterest);

    return 0;
}