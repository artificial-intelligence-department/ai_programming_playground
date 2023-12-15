#include <stdio.h>
#include <cmath> 

float rate;
double compaundinterest, principal ;
int years,  times;
char name[100];

int main(){

     printf("Enter your name:\n");
     scanf("%s",&name);
     printf("Enter the principal amount:\n");
     scanf("%lf",&principal);
     printf("Enter the rate of interest (in percentage):\n");
     scanf("%f",&rate);
     printf("Enter the number of years:\n");
     scanf("%d",&years);
     printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):\n");
     scanf("%d",&times);

     rate = rate/100;
     compaundinterest = principal*pow(1+rate/times,times*years);
     compaundinterest=compaundinterest-principal;
     rate=rate*100;

     printf("Hello ,%s\nthe compound interest for a principal of %.2lf,at a rate of %.2f%%,compounded %d times a year, for %d years is: %.2lf" ,name, principal,rate,years,times,compaundinterest);

}