#include <cstdio>
#include <cmath>

int main(){
    char name[50];
    double principal, rate, output, total_amount;
    int years, period;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d", &period);

    rate /= 100; 
    total_amount = principal * pow(1 + rate/period, period*years);
    output = total_amount - principal;

    printf("%.2f\n", output);
    printf("Hello, %s The compound interest for a principal of %.2f at a rate of %.2f %% compounded %d times a year for %d years is: %.2f\n", name, principal, rate, period, years, output);
    printf("The total amount after %d years is: %.2f", years, total_amount);
    return 0;
}