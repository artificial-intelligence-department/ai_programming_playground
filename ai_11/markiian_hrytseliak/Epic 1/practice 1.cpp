#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double sum;
    int compound;
    double rate;
    int time;

    char name [200];
    printf("Your name: ");
    scanf("%s",& name);
    printf("Please enter your deposit amount: ");
    scanf("%lf",& sum);
    printf("Please enter amount of years: ");
    scanf("%d",& time);
    printf("Please enter percentage rate: ");
    scanf("%lf",& rate);
    printf("Please enter the number of times interest is compouded per year: ");
    scanf("%d",& compound);
    printf("Hello, %s!\n",name);
    double x=sum*pow((1+((rate/100)/compound)),compound*time)-sum;
    double y=x+sum ;
    printf("The compound interest for a principal of %lf at a rate of %.2f%% compounded %d times a year for %d years is: %lf (your profit)\n",sum,rate,compound,time,x);
    printf("The amount after %d years is: %lf\n",time,y);
    return 0;

}