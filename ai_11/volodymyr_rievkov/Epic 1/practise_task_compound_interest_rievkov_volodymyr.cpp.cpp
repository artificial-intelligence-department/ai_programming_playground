#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    string name;
    double startAmount = 0;
    double rate;
    int years;
    int compound;
    double endAmount;
    double generalAmount;
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter the principal amount: ");
    scanf("%lf", &startAmount);
    printf("Enter the rate of interest: ");
    scanf("%lf", &rate);
    printf("Enter number of years: ");
    scanf("%d", &years);
    printf("Enter the number of times interest compounded per year: ");
    cin >> compound;
    endAmount = (startAmount * pow((1 + rate/compound), compound * years)) - startAmount; 
    generalAmount = startAmount + endAmount; 
    printf("Hello %s! \n", &name);
    printf("The compound of interest for a principal of %lf at a rate of %lf compounded %d times a year for %d years is %lf \n", startAmount, rate/100, compound, years, endAmount);
    printf("The general amount is %lf", generalAmount);
}