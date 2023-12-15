#include <stdio.h>
#include <math.h>

int main() {
    char name[100];
    double principal, rate, time, compound_frequency;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter amount: ");
    scanf("%lf", &principal);

    printf("Enter percentage: ");
    scanf("%lf", &rate);

    printf("Enter the number of years: ");
    scanf("%lf", &time);

    printf("Enter the number of charges per year: ");
    scanf("%lf", &compound_frequency);

    rate = rate / 100;

    double amount = principal * pow(1 + rate / compound_frequency, compound_frequency * time);
    double compound_interest = amount - principal;

    printf("Hello, %s!\n", name);
    printf("Compound interest: %.2lf\n", compound_interest);
    printf("Total amount after %.2lf years: %.2lf\n", time, amount);

    return 0;
}