#include <cstdio>
#include <cmath>

int main() {
    int years, number;
    float principal, compoundInterest, rate; 
    char name[20];
    
    printf("Enter your name: \n");
    scanf("%s", name); 
    
    printf("Enter the principal amount: \n");
    scanf("%f", &principal);

    printf("Enter the rate of interest (e.g 0.05 if it is 5%%): \n"); 
    scanf("%f", &rate);

    printf("Enter the number of years: \n");
    scanf("%d", &years); 

    printf("Enter the number of times interest is compounded per year (e.g.1 for annually, 4 for quarterly, 12 for monthly): \n");
    scanf("%d", &number); 

    compoundInterest = principal * pow((1 + (rate / number)), number * years);

    printf("Hello, %s!\n", name); 

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %i times a year for %i years is: %.2f\n",
           principal, rate * 100, number, years, compoundInterest); 

    printf("The total amount after %d years is: %.2f\n", years, compoundInterest); 
    return 0;
}