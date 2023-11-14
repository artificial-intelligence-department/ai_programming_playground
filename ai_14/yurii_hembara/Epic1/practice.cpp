#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
    string name;
    int years, period;
    double principal, rate;
    double results;

    printf("Your name: ");
    scanf("%s", &name);

    printf("\nPrincipal: ");
    scanf("%lf", &principal);

    printf("\nNumber of years: ");
    scanf("%i", &years);

    printf("\nPeriod(1 - yearly, 4 - quarters, 12 - monthly)");
    scanf("%i", &period);

    printf("\nRate: ");
    scanf("%lf", &rate);

    results = principal * pow((1 + rate/period), years*period);

    printf("\nResult is: %lf \n", results);

    return 0;
}
