#include <stdio.h>
#include <cmath>

int main() {
    char name[100];
    double principal, rate;
    int years, compaunded; 

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    
    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &compaunded); 

    rate /= 100;  
    double amount = principal * pow(1 + (rate / compaunded), compaunded * years);

    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf compounded %d times a year for %d years is: %.2lf\n", principal, rate * 100, compaunded, years, amount - principal);
    printf("The total amount after %.0d years is: %.2lf\n", years, amount);

    return 0;
}
