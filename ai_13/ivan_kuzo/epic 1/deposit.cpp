#include <cstdio>
#include <cmath>
int main(){

    double sum;
    double percentage;
    int years;
    int period;
    char name[50];
    printf ("Enter your name:\n");
    scanf ("%s", &name);

    printf ("Enter sum of deposit:\n");
    scanf ("%lf", &sum);
    printf ("Enter your rate:\n");
    scanf ("%lf", &percentage);
    printf ("Enter number of years:\n");
    scanf ("%i", &years);
    printf ("Enter the number of times interest is compouded:\n ");
    scanf ("%i", &period);

    double result=pow(1+percentage/100/period,period*years);
    result*=sum;
    double result2=result-sum;
    printf("Hello %s\n",name);
    printf("The compound interest for a principal of %.lf at a rate of %.1lf%% compounded %.i times a year for %.i years is: %.lf\n",sum,percentage,period,years,result2);
    printf("The total amount after %.i years is: %.lf",years,result);

  return 0;
}