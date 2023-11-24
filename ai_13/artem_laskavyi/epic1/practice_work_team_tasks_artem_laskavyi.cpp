#include <cstdio>
#include <cmath>

    char name[100];
    double pricipal;
    double rate;
    int years;
    int period;
    double compoundInterest;

int main(){
    
    printf("Enter your name:");
    scanf ("%s", name);

    printf("Enter the pricipal amount:");
    scanf ("%lf", &pricipal);

    printf("Enter the rate of interest (in percentage):");
    scanf ("%lf", &rate);

    printf("Enter the number of years:");
    scanf ("%u", &years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):");
    scanf ("%u", &period);

    double compoundInterest = pricipal*pow((1+(rate/period)),period*years);

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", pricipal, rate * 100, period, years, compoundInterest);

    return 0;
}