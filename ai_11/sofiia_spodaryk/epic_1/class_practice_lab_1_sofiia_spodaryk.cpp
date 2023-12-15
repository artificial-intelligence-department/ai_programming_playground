#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    char name[15];
    double amount, rate, number, years;
    

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &amount);
    printf("Enter the rate of interest: ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%lf", &years);
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%lf", &number);

    double deposit = amount * pow((1 + rate / 100.0), years);

    printf("Hello %s!\n", name);
    printf("The compound interest for a principal of %.0lf at a rate of %.0lf compounded %.0lf times a year for %.0lf years is: %.2lf\n", amount, rate, number, years, deposit);
return 0;  
}
