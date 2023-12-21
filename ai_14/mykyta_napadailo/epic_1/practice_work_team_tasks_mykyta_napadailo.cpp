#include <cstdio>
#include <cmath>

int main()
{
    char name[100];
    double principal, rate;
    int years, period;
    // Ввід імені
    printf("Enter your name: ");    
    scanf("%99[^\n]", name);
    // Ввід початкової суми
    printf("Enter your principal amount: ");
    scanf("%lf", &principal);
    // Ввід відсоткової ставки
    printf("Enter your rate of interest: ");
    scanf("%lf", &rate);
    // Ввід кількості років
    printf("Enter your number of years: ");
    scanf("%i", &years);
    // Ввід кількості нарахувань за рік
    printf("Enter your number of times interest is compounded per year: ");
    scanf("%i", &period);

    rate /= 100;
    double amount = principal * pow((1 + (rate / period)), period * years);
    printf("Hello %s!\nThe compound interest for a principal of %.2f at a rate of %.2f%% compounded %i times a year for %i years is: %.2f\n", name, principal, rate * 100, period, years, amount - principal);
    printf("The total amount after %i years is %.2f\n", years, amount);

    return 0;
}

