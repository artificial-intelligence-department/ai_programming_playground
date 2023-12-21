#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    char name[100];
    double sum, rate, total_amount;    
    int years, period;
    printf("Enter your name:" );
    scanf("%99[^\n]", name); 
    printf("Enter the principal amount:" );
    scanf("%lf",&sum);
    printf("Enter the rate fo interest in percentage:" );
    scanf("%lf",&rate);
    printf("Enter the number of years:" );
    scanf("%d",&years);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):" );
    scanf("%d",&period);
    total_amount = sum * pow((1 + (rate/100)/period), period*years);
    printf("Hello, %s\n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %d times a year for %d years is: %.2lf\n", sum, rate, period, years, total_amount);
}