#include <iostream> 
#include <cmath>
#include <stdio.h>
using namespace std;
int main() 
{
    double principal, sum, rate;
    int time, number;
    char name[50];

    printf("Enter your name: ");
    scanf("%s", &name);  
    printf("Please enter deposit amount: ");
    scanf("%lf", &principal);
    printf("Please enter the rate of interest(in persentage): ");
    scanf("%lf", &rate);
    printf("Please enter the number of compounding: ");
    scanf("%d", &number);
    printf("Please enter amount of years: ");
    scanf("%d", &time);
    printf("Hello %s\n", name);
    sum = principal;
    for (int i = 0; i < number * time; i++){
       sum = sum * (1 + rate/100); 
    } 
    sum = sum - principal;
    printf("The compound interest for a principal of %.1f$ at a rate of %.1f%% compounded %d time a year for %d years is: %.2f$\n", principal, rate , number, time, sum);
    return 0;
}