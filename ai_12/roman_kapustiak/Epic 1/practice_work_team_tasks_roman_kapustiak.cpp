#include <cstdio>
#include <cmath>


int main()
{
    char name[50];
    double principal, rate;
    int years, timesInterestIsCompounded;

    double compoundInterest, totalAmount;

    printf("Enter your name: ");
    if(!scanf("%s", name))
    {   
        printf("Wrong input!\n");
        return 1;
    }

    printf("Enter the principal amount: ");    ;
    if(!scanf("%lf", &principal))
    {   
        printf("Wrong input!\n");
        return 1;
    }


    printf("Enter the rate of interest (in percentage): ");
    if(!scanf("%lf", &rate))
    {   
        printf("Wrong input!\n");
        return 1;
    }    

    printf("Enter the number of years: ");    
    if(!scanf("%i", &years))
    {   
        printf("Wrong input!\n");
        return 1;
    }  

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    if(!scanf("%i", &timesInterestIsCompounded))
    {   
        printf("Wrong input!\n");
        return 1;
    }  

    rate /= 100;

    totalAmount = principal * pow ((1 + rate / timesInterestIsCompounded), timesInterestIsCompounded * years);
    compoundInterest = totalAmount - principal;

    printf("Hello %s!\n", name);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, timesInterestIsCompounded, years, compoundInterest);
    printf("The total amount after %i years is: %.2f", years, totalAmount);

    return 0;
}