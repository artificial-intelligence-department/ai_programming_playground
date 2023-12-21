#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    char name [100];
    double p;
    double r;
    int t;
    int n;
    printf("Enter your name: \n");
    scanf("%s", name);
    
    
    printf("Enter the principal amount: \n");
    scanf("%lf", &p);


    printf("Enter the rate  of interest (in percentage): \n");
    scanf("%lf", &r);
    
    
    printf("Enter the number of years: \n");
    scanf("%d", &t);
    
    
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): \n");
    scanf("%d", &n);

    double a=p*pow((1+r/(100*n)), n*t);
    double b=a-p;

    printf("Hello %s!\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p, r, n, t, b);
    printf("The total amount after %d years is: %.2f\n", t, a);



    return 0;
}