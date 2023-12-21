#include <cstdio>  
#include <cmath>
int main()
{ 
    char name [100];
    int years, period;
    double rate, pricipal, A, r, s;
    
    printf("Enter your name:");
    scanf("%99[^\n]",name);
    
    printf("Enter the number of years:");
    scanf("%d", &years);
   
    printf("Enter the number of times interest is compounded per year:");
    scanf("%d", &period); 
   
    printf("Enter the rate of interest:");
    scanf("%lf", &rate);
    
    printf("Enter the principal amount:");
    scanf("%lf", &pricipal);
    
    printf("\n\n");

    r=rate/100;
    A=pricipal*pow(1+(r/period),period*years);
    s=A-pricipal;
    
    printf("Hi, %s.\nThe compound interest for a prinsipal of %lf at a rate of %lf%%  compounded %d times a year for %d years is:%2f. \nTotal amount after %d years is: %2f", name, pricipal, rate, period, years, s, years, A);
    return 0;
}