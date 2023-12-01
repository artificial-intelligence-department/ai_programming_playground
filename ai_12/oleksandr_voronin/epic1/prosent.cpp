#include <cstdio>
#include <cmath>

int main(){

char name [50];
double principal,rate,totalAmount,compoundInteresto;
int years;
int period;
int a;
printf ("Enter your name:");
scanf ("%s", name);
printf ("Enter your prinsipal amount:");
scanf("%lf", &principal);
printf ("Enter the rate:");
scanf("%lf", &rate);
printf ("Enter the number of years:");
scanf("%i", &years);
printf("Enter the number of times interest is compounded per year:");
scanf("%d", &period);

rate/=(double) 100;
totalAmount = principal * pow(1+(rate/period),period * years);
compoundInteresto = totalAmount - principal;
printf ("Hello %s \n",name);
printf ("the compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, compoundInteresto);
printf ("Total is %.2f",totalAmount);

return 0;


}