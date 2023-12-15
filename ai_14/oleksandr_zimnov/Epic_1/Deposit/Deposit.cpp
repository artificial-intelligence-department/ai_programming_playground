#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    float total_amount, rate;
    int year, amount, period;
    char name[100]; 

    printf("Enter name: ");
    scanf("%s", name); 

    printf("Enter your principal amount: ");
    scanf("%d", &amount);

    printf("Enter rate of interest (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the number of years: ");
    scanf("%d", &year);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d", &period);

    total_amount = amount * pow((1 + rate / 100 / period), period * year);

    printf("Hello, %s\n", name);
    printf("The compound interest for a principal of %d at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate, period, year, total_amount - amount);
    printf("The total amount after %d years is: %.2f\n", year, total_amount);
}
