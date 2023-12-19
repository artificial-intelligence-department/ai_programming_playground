#include <stdio.h>
#include <math.h>

int main() {
    char name[20];
    double amount, rate, s, res;
    int years, per;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &amount);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &per);
     s = amount*pow(1+(rate/100*per), per*years);
    res=s-amount;
    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %d times a year for %d years is: %.2lf\n", amount, rate, per, years, res);
    printf("The total amount after %d years is: %.2lf\n", years, s);

    return 0;
}