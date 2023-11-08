#include <iostream>
#include <cmath>

int main() 
{
    double a0, p, fr, n;
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &a0);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &p);
    printf("Enter the number of years: ");
    scanf("%lf", &n);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%lf", &fr);
    if(fr!=1&&fr!=4&&fr!=12)
    {printf("Wrong input. Try again and choose one of the following: 1 for annually, 4 for quarterly, 12 for monthly\n");
    return 0;}

    double amount=a0*pow(1+((p/100)/fr), fr*n);
    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %.2lf times a year for %.2lf years is: %.2lf\n", a0, p, fr, n, (amount - a0));
    printf("The total amount after %.2lf years is: %.2lf\n", n, amount);

    return 0;
}