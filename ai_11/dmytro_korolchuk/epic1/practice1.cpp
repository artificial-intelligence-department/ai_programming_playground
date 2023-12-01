#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    char name[150];
    printf("Enter your name: ");
    scanf("%149s", name);

    double amount;
    printf("Enter the principal amount: ");
    scanf("%lf", &amount);

    double rate;
    printf("Enter the rate of interest(in percentage): ");
    scanf("%lf", &rate);

    int years;
    printf("Enter the number of years: ");
    scanf("%d", &years);

    int period;
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &period);

    rate=rate/100;
    double result = amount * pow(1+(rate/period), period*years);
    double income = result - amount; 
    
    printf("Hello %s\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate * 100, period, years, result);
}
