#include<iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    char name[20];
    int years, compound;
    double depositAmount = 0;
    double rate;
    double result;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter years: ");
    scanf_s("%d", &years);
    printf("Enter deposit amount: ");

    scanf_s("%lf", &depositAmount);
    printf("Enter rate: ");
    scanf_s("%lf", &rate);
    printf("Enter compound: ");
    scanf_s("%d", &compound);


    result = depositAmount * pow(1 + (rate / (100 * compound)), (years * compound));
    result = result - depositAmount;

    printf("Hello, %s\n", name);
    printf("The compound interest of %.2f at a rate of %.2f%% for %d years is %.2f\n", depositAmount, rate, years, result);

    return 0;
}

