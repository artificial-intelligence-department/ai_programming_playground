//
// Created by olehio-p on 10/27/2023.
//
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
    char name[30];
    int years, compound;
    double principal, rate, compoundInterest, accruedAmount;

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Enter the principal amount: ");
    scanf_s("%lf", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf_s("%lf", &rate);

    printf("Enter the number of years: ");
    scanf_s("%d", &years);

    printf("Enter the number of times interest is compounded per year "
           "(e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf_s("%d", &compound);

    accruedAmount = principal * pow((1 + (rate / (100 * compound))), years * compound);
    compoundInterest = accruedAmount - principal;

    printf("-------------------------------------------------------------"
           "-------------------------------------------------------------\n");

    printf("Hello, %s\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% "
           "compounded %d times a year for %d years is: %.2f\n",
           principal, rate, compound, years, compoundInterest);
    printf("The total amount after %d years is: %.2f\n", years, accruedAmount);

    return 0;
}