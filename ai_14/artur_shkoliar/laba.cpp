#include <stdio.h>
#include <cmath>

int main()
{
    double principal;
    double rate;
    int years;
    char name[100];
    int period;

    printf("Enter your name: \n");
    scanf("%s", name);

    printf("Enter the principal amount: \n");
    scanf("%lf", &principal);

    printf("Enter the rate of interest: \n");
    scanf("%lf", &rate);

    printf("Enter the amount of years: \n");
    scanf("%d", &years);

    printf("Enter the nubers of times interest is compounded per year(1 for anually, 4 for quartly, 12 for monthly): \n");
    scanf("%d", &period);

    rate /= 100;

    double bill = principal * pow((1 + (rate/period)), period * years);
    double difference = bill - principal;

    printf("Hello, %s \n! The compound interest for a principal of %lf at a rate of %lf%% compounded %d times a year for %d year(s) is %lf \n The total amount after %d year(s) is:%lf ",name, principal,rate*100,period,years,difference,years,bill);

    

    return 0;
}