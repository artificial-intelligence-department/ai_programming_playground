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
    printf("%s\n", name);

    printf("Enter the principal amount:");
    scanf("%lf", &pricipal);
    printf("%lf\n", pricipal);

    printf("Enter the rate of interest:");
    scanf("%lf", &rate);
    printf("%lf\n", rate);
    rate = rate *0.01;

    printf("Enter the number of years:");
    scanf("%d", &years);
    printf("%d\n", years);

    printf("Enter the number of times interest is compounded per year:");
    scanf("%d", &times);
    printf("%d\n", times);

    double A = pricipal * pow((1 + (rate / times)), times * years);
    double B = pricipal - A;
    double G {0.1234};
    printf("Hello %s!\n",name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n ", pricipal, rate * 100, times, years, B);
    printf("The total amount after 3 years is %.2f",A);
  
    return 0;
}