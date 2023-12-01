#include <stdio.h>
#include <math.h>

char name[100];
double principal;
double rate;
double years;
int period;
double compoundInterest;

int main() {
    printf("Enter Your Name: ");
    scanf("%s", &name);
    
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    

    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    

    printf("Enter the number of years: ");
    scanf("%lf", &years);


    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &period);
    

    double amount = principal * pow(1 + rate / (100 * period), period * years);
    printf("The amount is %.2lf\n", amount);


    double compoundInterest = principal * pow(1 + rate / period, period * years) - principal;
    printf("The compound interest for a principal of %.2.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, compoundInterest);


    return 0;
}