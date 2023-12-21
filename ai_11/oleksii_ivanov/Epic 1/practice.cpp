#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    char name[51];
    double principal, rate, amount, years;
    int period;

    printf("Enter name: ");
    scanf_s("%50s", name);

    // principal is money invested
    printf("Enter the principal amount: ");
    scanf_s("%lf", &principal);

    printf("Enter interest rate in percents: ");
    scanf_s("%lf", &rate);
    rate /= 100;

    printf("And how many years? ");
    scanf_s("%lf", &years);

    printf("Enter the time when interest is compounded per year "
           "(1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf_s("%d", &period);

    amount = principal * pow((1 + rate / period), period * years);

    printf("Hello, %s!\n"
           "The compound interest for a principal of %.2f "
           "at a rate of %.2f%% "
           "compounded %d times a year "
           "for %f years is: %.2f\n",
           name, principal, rate * 100, period, years, amount);

    return 0;
}
