#include <iostream> 
#include <cmath>
using namespace std;

int main() 
{
    double principal, compoundInterest, rate;
    int years, n;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("deposit amount: ");
    scanf("%lf", &principal);

    printf("Please enter the rate of interest (0-100%%): ");
    scanf("%lf", &rate);

    printf("number of compounding (1, 4 or 12): ");
    scanf("%d", &n);

    printf("amount of years: ");
    scanf("%d", &years);


    printf("Hi %s\n", name);

    compoundInterest = principal;

    for(int i = 0; i < (n * years); i++)
    {
        compoundInterest = compoundInterest + compoundInterest*rate/100;
    }

    compoundInterest = compoundInterest - principal;
    printf("The compound interest for a principal of %.1f$ at a rate of %.1f%% compounded %d time a year for %d years is: %.2f$\n", principal, rate, n, years, compoundInterest);
    return 0;
}