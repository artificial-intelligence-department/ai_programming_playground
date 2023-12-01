#include <stdio.h>
#include <math.h>

int main() {
    char name[100];
    double principal, rate, time;
    int compoundFrequency;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%lf", &time);
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &compoundFrequency);

    rate = rate / 100.0;

    double amount = principal * pow(1 + (rate / compoundFrequency), compoundFrequency * time);
    double compoundInterest = amount - principal;

    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %d times a year for %.2lf years is: %.2lf\n", principal, rate * 100, compoundFrequency, time, compoundInterest);
    printf("The total amount after %.2lf years is: %.2lf\n", time, amount);

    return 0;
}
