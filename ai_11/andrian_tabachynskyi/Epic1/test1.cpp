
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int startkap, year, vic;
    double result;
    char name[50];

    printf("Enter your name : ");
    scanf_s("%s", &name, 50);
    printf("\nEnter the principal amount: ");
    scanf_s("%i", &startkap);
    printf("\nEnter the rate of interest(in percentage): ");
    scanf_s("%i", &vic);
    printf("\nEnter the number of years: ");
    scanf_s("%i", &year);

    result = startkap * pow(1 + (vic/100.0), year);
 
    printf("\n%f", result );
    
    printf("\nHello, %s", name);
}

