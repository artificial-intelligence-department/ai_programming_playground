#include <iostream>
#include <string>
#include <cstdio>

int main() {
    char name[100];
    int principal;
    double rate, time, n;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%d", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%lf", &time);
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%lf", &n);

    rate = rate / 100;
    double amount = principal;
    for (int i = 0; i < static_cast<int>(n * time); i++) {
        amount *= (1 + rate / n);
    }
    double compoundInterest = amount - principal;

    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %d at a rate of %.2lf%% compounded %.0lf times a year for %.2lf years is: %.2lf\n", principal, rate * 100, n, time, compoundInterest);
    printf("The total amount after %.2lf years is: %.2lf\n", time, amount);

    return 0;
}
