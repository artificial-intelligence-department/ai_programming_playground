#include <cstdio>
#include <cmath>

int main() {
    char* name[50];
    double principal, rate, amount, income;
    int time, compoundingNum;

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interests (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the number of years: ");
    scanf("%d", &time);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d", &compoundingNum);

    rate = rate / 100;
    amount = principal * pow(1 + (rate / compoundingNum), compoundingNum * time);
    income = amount - principal;

    printf("Hello, %s! \n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, compoundingNum, time, income);
    printf("The total amount after %d years is: %.2lf", time, amount);

    return 0;
}
