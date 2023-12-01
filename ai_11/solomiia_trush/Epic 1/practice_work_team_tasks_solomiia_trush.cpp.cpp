#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(void) {
    char name [40];
    float amount;
    float rate;
    int years;
    int interest_compound;

    printf ("Enter your name: "); 
    scanf ("%s", &name);
    printf ("Enter the principal amount: ");
    scanf ("%f", &amount);
    printf("Enter the rate of interest: ");
    scanf ("%f", &rate);
    printf ("Enter the number of years: ");
    scanf("%d", &years) ;
    printf ("Enter the number of times interest is compounded per year: ");
    scanf ("%d", &interest_compound );

    float x = amount* pow((1+rate/(100*interest_compound)),(interest_compound*years));

    printf("Hello, %s\n", name);
    printf("The compound interest of %.2f at a rate of %.2f%% for %d years is %.2f\n", amount, rate, years, x);

}