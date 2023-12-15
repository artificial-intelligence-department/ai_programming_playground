#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double principal, rate, result;
char name [100];
int years, period;


int main(){

    printf("Enter your name:");
    scanf("%s", name);
    
    printf("Enter the pricipal amount:");
    scanf("%lf", &principal);

    printf("Enter the rate");
    scanf("%lf", &rate);

    printf("Enter the preiod (1 for annually 4 for quarterly, 12 for monthly)");
    scanf("%u", &period);

    printf("Enter the years:");
    scanf("%u", &years);

    result = principal*pow((1+(rate/period)),period*years);

    printf("The compound interest for a principal of %.2f at rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, result);

    return 0;
}