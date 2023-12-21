#include <stdio.h>
#include <math.h>

int main() {
    char name[50];
    double principal, rate, compoundInterest, totalAmount;
    int years, n;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &n);

    rate = rate / 100; 
    totalAmount = principal * pow(1 + rate / n, n * years);
    compoundInterest = totalAmount - principal;

   
    printf("\nHello, %s!\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, years, compoundInterest);
    printf("The total amount after %d years is: %.2f\n", years, totalAmount);

    return 0;
}