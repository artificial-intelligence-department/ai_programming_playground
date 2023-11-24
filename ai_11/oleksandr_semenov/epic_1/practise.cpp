#include <iostream>

using namespace std;
int main()
{
    double principal, rate, compoundInterest;
    int n, years;
    char name[100];

    printf("Напишіть своє ім'я: ");
    scanf("%s", &name);

    printf("Введіть вклад: ");
    scanf("%lf", &principal);
    printf("Введіть відсотки десятковим дробом: ");
    scanf("%lf", &rate);
    printf("Введіть кількість нарахування: ");
    scanf("%d", &n);
    printf("Введіть роки: ");
    scanf("%d", &years);

    printf("Hello %s\n", name);

    compoundInterest = principal;
    for (int i = 0; i < n * years; i++)
        compoundInterest = compoundInterest * (1 + rate);

    compoundInterest = compoundInterest - principal;

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, years, compoundInterest);
    return 0;
}