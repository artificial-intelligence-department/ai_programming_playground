#include<iostream>
#include<math.h>


int main(){
    string name;
    int years, period;
    double principal, rate;
    double results;

    printf("State your name: ");
    scanf("%s", &name);

    printf("\nState your principal: ");
    scanf("%lf", &principal);

    printf("\nState the number of years: ");
    scanf("%i", &years);

    printf("\nState the period(1 for yearly, 4 for quarters, 12 for monthly)");
    scanf("%i", &period);

    printf("\nState the rate: ");
    scanf("%lf", &rate);

    results = principal * pow((1 + rate/period), years*period);

    printf("\nResult is: %.2lf \n", results);

    return 0;
}
