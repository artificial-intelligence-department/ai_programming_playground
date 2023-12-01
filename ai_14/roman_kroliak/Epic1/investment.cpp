#include <iostream>
#include <cmath>
int main(){
    char name[50];
    double amount, rate;
    int years, period;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter amount of investment: ");
    scanf("%lf", &amount);
    printf("Enter percent rate: ");
    scanf("%lf", &rate);
    printf("Enter the investment term in years: ");
    scanf("%d", &years);
    printf("Enter the number of times interest is compounded per year(e.g., 1 for annually, 4 for quartly, 12 for monthly): ");
    scanf("%d", &period);
    double bill = amount * pow((1 + (rate/100/period)), period*years );
    double profit = bill - amount;
    printf("Hello, %s! \nThe profit for a amount of %.2f at rate of %.2f%% compounded %d times a year for %d year(s) is: %.2f \nThe total amount after %d year(s) is: %.2f", name, amount, rate, period, years, profit, years, bill);
    return 0;
}