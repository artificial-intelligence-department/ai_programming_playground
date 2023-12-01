#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Creating and entering user's name
    char name[25];
    printf("Your name: ");
    scanf("%s", &name);

    // Creating and entering user's deposit amount
    double sum;
    printf("Enter deposit amount: ");
    scanf("%lf", &sum);

    // Creating and entering user's deposit amount of years
    int years;
    printf("Enter amount of years: ");
    scanf("%d", &years);

    // Creating and entering user's deposit rate
    double percent;
    printf("Enter deposit rate: ");
    scanf("%lf", &percent);

    // Calulating value that user will recieve
    double result = sum * pow((1 + percent * 0.01), years);

    // Output result value
    printf("Thank you %s \nYou will receive: %lf", name, result);
    return 0;
}
