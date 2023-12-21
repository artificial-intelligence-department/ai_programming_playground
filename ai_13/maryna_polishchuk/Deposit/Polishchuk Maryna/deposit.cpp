#include <cstdio>
#include <cmath>

int main()
{
    char name[50];
printf("Enter your name \n");
scanf ("%49[^\n]", name);

 double principal;
printf("Enter the principal amount \n");
scanf ("%lf", &principal);

double rate;
printf("Enter the rate of interest (in percentage) \n");
scanf ("%lf", &rate);

int years;
printf("Enter the number of years \n");
scanf ("%d", &years);

int period;
printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly) \n");
scanf ("%d", &period);

double res;

res = principal * pow((1 + rate / 100), years * period);

printf("Hello, %s \n", name);
printf ("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, res);

return 0;
}