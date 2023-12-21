#include <iostream>
int main() {
    double principal, rate;
    int years;
    printf("Sum: ");
    scanf("%lf", &principal);
    printf("Years (%): ");
    scanf("%lf", &rate);
    printf("Enter the investment term in years: ");
    scanf("%d", &years);
    double amount = principal * (1 + rate / 100.0 * years);
    printf("Profit after %d years: $%.2f\n", years, amount);

    return 0;
}