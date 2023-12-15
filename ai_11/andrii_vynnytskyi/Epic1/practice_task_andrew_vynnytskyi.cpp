#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int years, times;
    double start_capital, percent;
    char name[100];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your start capital: ");
    scanf("%lf", &start_capital);

    printf("Enter the percents: : ");
    scanf("%lf", &percent);

    printf("And how many times do you take money? ");
    scanf("%d", &times);

    printf("And how many years? ");
    scanf("%d", &years);

    double result = start_capital * pow(1 + percent / 100.0, years*times);

   printf("Hello, %s!\nYour start capital is %.2f\nAnd is set at  %.2f%% for %d  years,\nyour profit is %.2f\n",name, start_capital, percent, years, result);
    return 0;
}