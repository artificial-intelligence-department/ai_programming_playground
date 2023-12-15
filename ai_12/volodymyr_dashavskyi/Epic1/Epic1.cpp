#include <cstdio>
#include <cmath>

int main(){

char name [20];
double deposit,interest,finalAmount,profit;
int years;
int period;

printf ("Enter your name:");
scanf ("%s", &name);

printf ("Enter your deposit:");
scanf("%lf", &deposit);

printf ("Enter the interest:");
scanf("%lf", &interest);

printf("enter period:"); 
scanf("%d", &period);

printf ("Enter the number of years:");         
scanf("%i", &years);

interest/=(double) 100;
finalAmount = deposit * pow(1+(interest/period),period * years);
profit = finalAmount - deposit;

printf ("Hello %s \n",name);
printf ("The profit from your deposit of %.2f at a interest of %.2f%% compounded %d times a year for %d years is: %.2f\n", deposit, interest * 100, period, years, profit);
printf ("your final Amount is %.2f",finalAmount);


return 0;
}