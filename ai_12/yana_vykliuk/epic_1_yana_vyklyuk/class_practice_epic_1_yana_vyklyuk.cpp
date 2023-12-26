#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
    char name[60];
    double p, r, q, a; 
    int n, t;
    
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your principal: ");
    scanf("%lf", &p);

    printf("Enter rate: ");
    scanf("%lf", &r);

    printf("Enter years: ");
    scanf("%d", &t);

    printf("Enter period: ");
    scanf("%d", &n);

    r = r / 100;
    a = p * pow(1+(r/n),n*t);
    q = a - p;

    printf("The compaund interest for a principal of %.2f at a rate of %.2f%% compaunded %d times a year for %d years is: %.2f\n", p, (r*100), n, t, q);
    printf("Total is: %.2f\n", a);
    
    return 0;
}