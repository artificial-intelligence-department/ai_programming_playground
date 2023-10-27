

#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>



int main()
{
    char name[30];
    int princAm {0};
    double rate;
    int years {0};
    int times {0};

    
    float total {princAm};
    printf("%s", "Enter your name: \n");

    
    scanf("%s",name );


    printf("%s", "Enter the principal amount: \n");

    scanf("%d",&princAm );
    

    printf("%s", "Enter the rate of interest (in percentage): \n");

    scanf("%lf", &rate );






    printf("%s", "Enter the number of years:  \n");
    scanf("%d", &years );

    printf("%s", "Enter the number of times interest is compounded per year  \n");
    scanf("%d", &times );


    
    total = princAm* pow((1 + rate/100/times), times*years) ;
  
    
    printf("Hello, %s \n", name);
    printf("The compound interest for a principal of %d at a rate of %lf compounded %d times a year for %d years is %f \n", princAm,rate,times,years, total-princAm);
    printf( "The total amount after 3 years is: %f",total);
    // printf(name, "Hello, %s ");
    // printf("%s", "The compound interest for a principal of ");
    // printf("%s", " at a rate of 5.00%");
    // printf("%s", "  compounded 4 times a year ");
    // printf("%s", "  for 3 years is: 8037.73");
    // printf("%s", "The total amount after 3 years is: 58037.73");

    return 0;
}
