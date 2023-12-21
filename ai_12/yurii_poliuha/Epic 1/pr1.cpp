#include<iostream>
#include<stdio.h>
#include<cmath>

int main(){
    char n[50];
    int y, per;
    double r, p;
    printf("Enter your name ");
    scanf("%s",n);
    printf("Enter the principal amount ");
    scanf("%lf",&p);
    printf("Enter the rate of interest (in percentage) ");
    scanf("%lf",&r);
    printf("Enter the number of years ");
    scanf("%d",&y);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly) ");
    scanf("%d",&per);

    r = r / 100;
    double A = p * pow((1 + r / per), per * y);
    printf("\nHello %s!\nThe compound interest for a principal of %.2lf at a rate of %.2lf%% compaunded %d times a year for %d years is: %.2lf",n, p, r, per, y, A - p);
    printf("\nThe total amount after %d years is %.2lf", y, A);

    return 0;
}