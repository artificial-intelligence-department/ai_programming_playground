#include <cstdio>
#include <cmath>

int main() {
    int number, years;
    float principal, rate, compoundInterest; 
    char name[39];
    
     printf("Enter your name: \n");
    scanf("%s", name); 

    printf("Enter the principal amount: \n");
    scanf("%f", &principal);

    printf("Enter the rate of interest (enter 0.9 if it is 90%%): \n"); 
    scanf("%f", &rate);

    printf("Enter the number of years: \n");
    scanf("%i", &years); 

    printf("Enter the number of times interest is compounded per year: \n");
    scanf("%i", &number); 

    compoundInterest = principal * pow((1 + (rate / number)), number * years);

    printf("Hello, %s!\n", name); 

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %i times a year for %i years is: %.2f\n",
           principal, rate * 100, number, years, compoundInterest); 

    printf("The total amount after %d years is: %.2f\n", years, compoundInterest); 
    return 0;
}
