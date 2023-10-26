#include <cstdio>
#include <cmath>


int main()
{
    char name[50];
    double principal, rate;
    int years, timesInterestIsCompounded;

    double compoundInterest, totalAmount;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the number of years: ");
    scanf("%i", &years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%i", &timesInterestIsCompounded);

    rate /= 100;

    totalAmount = principal * pow ((1 + rate / timesInterestIsCompounded), timesInterestIsCompounded * years);
    compoundInterest = totalAmount - principal;

    printf("Hello %s!\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, timesInterestIsCompounded, years, compoundInterest);
    printf("The total amount after %i years is: %.2f", years, totalAmount);

    return 0;
}