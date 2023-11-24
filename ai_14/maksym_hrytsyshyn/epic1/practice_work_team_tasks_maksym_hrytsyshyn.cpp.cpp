#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string name;
    int times;
    int years;
    double rate;
    double amount;
    double result;

    printf("Enter your name:");
    scanf("%99[^\n]", &name);
    printf("Enter the principal amount:");
    scanf("%lf", &amount);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%i", &years);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):");
    scanf("%i", &times);
    
    result = amount * pow((1+(rate/(100*times))), years*times)- amount;

    printf("Hello, %s!\n", &name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate, years, times, result);

    return 0;
}