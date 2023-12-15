#include <cmath>
#include <cstdio>

int main()
{
char name[50];
double principal;
double rate;
int time;
int n;
double allmoney, earned;

printf("Enter your name: ");
scanf("%s", name);

printf("Enter your principal: ");
scanf("%lf", &principal);

printf("Enter rate: ");
scanf("%lf", &rate);

printf("Enter years: ");
scanf("%d", &time);

printf("Enter period: ");
scanf("%d", &n);

rate /= 100;
allmoney = principal * pow(1+(rate/n), n*time);
earned = allmoney - principal;
printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, time, earned);
printf("Total is: %.2f", allmoney);

    return 0;
}