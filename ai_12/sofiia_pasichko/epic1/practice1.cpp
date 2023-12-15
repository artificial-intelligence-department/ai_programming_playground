#include <cstdio>
#include <cmath>
int main() {
char name [50];
double amount, rate;
int years, period;
double a, q;
printf ("Enter your name:");
scanf("%s", &name);
printf ("Enter the principal amount:");
scanf("%lf", &amount);
printf ("Enter the rate of interest (in percentage):");
scanf("%lf", &rate);
printf ("Enter the number of years:");
scanf("%d", &years);
printf ("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):");
scanf("%d", &period);

rate /= (double) 100;
a=amount * pow(1+(rate/period), period*years);
q=a-amount;
printf ("Hello %s\n", name);
printf( "The compound interest for a principal amount of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate*100, period, years, q);
printf("Total is: %.2f", a);
return 0;

}
