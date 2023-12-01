#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string name;
    float depositAmount;
    int years;
    float rate;
    int compound;

    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter your deposit amount: ");
    scanf("%f", &depositAmount);
    printf("Enter how long it will stake(in years): ");
    scanf("%i", &years);
    printf("Enter your percentage rate: ");
    scanf("%f", &rate);
    printf("Enter times it will be compounded yearly: ");
    scanf("%i", &compound);

    double result = depositAmount*pow((1+rate/100.0), compound*years);

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", depositAmount, rate, compound, years, result);
    printf("Your profit is: %.2f", result - depositAmount);
}
