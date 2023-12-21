#include <cstdio>
#include <cmath>

int main(){
    int years, compoundingNum;
    double rate, principal, amount, income;
    char name[100];

    printf("Enter your name:");
    scanf("%s[^\n]", &name);

    printf("Enter the principal amount:");
    scanf("%lf",&principal);

    printf("Enter the number of years:");
    scanf("%d",&years);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):");
    scanf("%d",&compoundingNum);

    printf("Enter the rate of interest (in percentage)");
    scanf("%lf",&rate);

    rate = rate/100;
    amount = principal * pow(1 +(rate / compoundingNum), compoundingNum * years); 
    income = amount - principal;

    printf("Hello, %s! \n", name);
    printf("The compound interest for a principal of %.2lf at a rate of %.2lf%% compounded %d times a year for %d year for %d years is: %.2f\n", principal , rate * 100, compoundingNum, years, income);
    printf("The total amount after %d years is: %.2lf", years, amount);   
    
    return 0;
}