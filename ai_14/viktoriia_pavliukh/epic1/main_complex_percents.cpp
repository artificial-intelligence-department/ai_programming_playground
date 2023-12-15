#include <iostream>
#include <cstdio>
#include <cmath>


int main(){
char name[100];
double principal, rate;
int years, period;

printf("Enter your name:");
scanf("%99[^\n]", name);

printf("Enter the principal amount:");
scanf("%lf", &principal);

printf("Enter the rate of interest (in percentage):");
scanf("%lf", &rate);

printf("Enter the number of years:");
scanf("%i", &years);

printf("Enter the number of times interest is compounded per year:");
scanf("%i", &period);
//get.line(cin);

 double a = principal*pow((1+(rate/100*period)),(period*years));
printf("%lf", a);

return 0;
}