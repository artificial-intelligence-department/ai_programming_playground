#include <cstdio>
#include <cmath>

int main ()
{
printf ("Enter your name: ");
char name[100];
scanf ("%s", name);

printf ("Enter the principal amount: ");
double principal, rate, A, total;
scanf ("%lf", &principal);

printf ("Enter the rate of interest (in percentage): ");
scanf ("%lf", &rate);

double r = rate / 100;

printf ("Enter the number of years: ");
int years, period;
scanf ("%d", &years);

printf ("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
scanf ("%d", &period);

A=principal*pow(1+r/period, period*years);
total=A-principal;

printf ("Hello, %s!\n", name);
printf ("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %d times a year for %d years is: %.2lf\n", principal, rate, period, years, total);
printf ("The total amount after %d years is: %.2lf", years, A);

return 0;
}
