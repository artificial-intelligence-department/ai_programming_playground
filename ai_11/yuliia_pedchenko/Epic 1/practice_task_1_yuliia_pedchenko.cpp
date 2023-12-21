#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

// Input: 

// Enter your name: Roman
// Enter the principal amount: 50000
// Enter the rate of interest (in percentage): 5
// Enter the number of years: 3
// Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): 4

// Output:

// Hello, Roman!
// The compound interest for a principal of 50000.00 at a rate of 5.00% compounded 4 times a year for 3 years is: 8037.73
// The total amount after 3 years is: 58037.73

int main() {
    int years;
    int num;
    float principal;
    float rate, compound_interest, total;
    char name[50];


    printf("Enter your name:\n");
    scanf("%s", name);

    printf("Enter the principal amount:\n");
    scanf("%f", &principal);

    printf("Enter the rate of interest (in percentage):\n");
    scanf("%f", &rate);

    printf("Enter the number of years:\n");
    scanf("%d", &years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):\n");
    scanf("%d", &num);


     total = principal * pow(( 1 + (rate / 100 / num)), ( num * years ));
     compound_interest = total - principal;


    printf("Hello, %s!\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate, num, years, compound_interest);
    printf("The total amount after %d years is: %.2f", years, total);

    return 0;
}
