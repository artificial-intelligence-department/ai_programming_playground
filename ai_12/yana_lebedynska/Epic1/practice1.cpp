#include <cstdio>
#include <cmath>

int main()
{
    int years, number;
    double amount, income, rate, principal;
    char* username[100];

    printf("Enter your name: ");
    scanf("%s", &username);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interests (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the term (in years): ");
    scanf("%d", &years);

    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &number);

    rate = rate / 100;
    amount = principal * pow(1 + (rate/number), number*years);
    income = amount - principal;

    printf("Hello, %s! ", username);
    printf("We've already done the calculations and here they are.\n");
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate*100, number, years, income);
    printf("The total amount that will be credited to your account after %d years is: %.2f\n", years, amount);

    return 0;

}