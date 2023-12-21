#include <cstdio>
#include <cmath>
char name[50];
double pricipal;
double rate;
int years;
int times;

int main()
{
    printf("Enter your name:");
    scanf("%s", name);
    printf("%s", name);
    printf("\n");

    printf("Enter the principal amount:");
    scanf("%lf", &pricipal);
    printf("%lf", pricipal);
    printf("\n");
    // 100%=1
    printf("Enter the rate of interest:");
    scanf("%lf", &rate);
    printf("%lf", rate);
    printf("\n");

    printf("Enter the number of years:");
    scanf("%d", &years);
    printf("%d", years);
    printf("\n");

    printf("Enter the number of times interest is compounded per year:");
    scanf("%d", &times);
    printf("%d", times);
    printf("\n");

    double A = pricipal * pow((1 + (rate / times)), times * years);

    printf("Hello, The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\times", pricipal, rate * 100, times, years, A);

    return 0;
}
