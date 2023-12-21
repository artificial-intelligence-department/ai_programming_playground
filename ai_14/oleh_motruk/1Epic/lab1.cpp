#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    const int buffersize = 100;
    char name[buffersize];
    double principal, rate, total_amount,n;
    int years, period;

    printf("Enter your name:");
    fgets(name , buffersize , stdin);

    printf("Enter your starting bid:");
    scanf("%lf", &principal);

    printf("Enter the bid percentage:");
    scanf("%lf" , &rate);

    printf("Enter the number of years:");
    scanf("%d" , &years);

    printf("Enter the number of interest charges per year: 1 for annual, 4 for quarterly, 12 for monthly:");
    scanf("%d" , &period);

    total_amount = principal * pow((1 + (rate/100)/period), period*years);

    n = (total_amount - principal);

    printf("Hello,%s!\nThe compound interest of a principal of %.2f at a rate of %.2lf%,  compounded %d times a year for %d years is:%.2lf\nThe total amount after %d years is: %.2f\n ", name , principal , rate,period,years,n,years,total_amount);


    return 0;
}