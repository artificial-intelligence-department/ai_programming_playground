#include <cmath>
#include <cstdio>

int main()
{
char name[50];
double p;
double r;
int t;
int n;
double a;
double q;

printf("Enter your name: ");
scanf("%s", name);

printf("Enter your principal: ");
scanf("%lf", &p);

printf("Enter rate: ");
scanf("%lf", &r);

printf("Enter years: ");
scanf("%d", &t);

printf("Enter period: ");
scanf("%d", &n);

r /= 100;
a = p * pow(1+(r/n), n*t);
q = a - p;
printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p, r * 100, n, t, q);
printf("Total is: %.2f", a);

    return 0;
}