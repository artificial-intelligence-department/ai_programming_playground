#include <cmath>
#include <cstdio> 

int main()
{
    char name [50];
    double principal;
    double rate; 
    int time;
    int n;      
    double totalamount,compoundInterest;

    printf("Enter your name ");
    scanf("%s",&name);
    printf("Enter the principal amount ");
    scanf("%lf",&principal);
    printf("Enter rate: ");
    scanf("%lf",&rate );
    printf("Enter the number of years: ");
    scanf("%d",&time);
    printf("Enter period: ");
    scanf("%d",&n);

    rate  /=(double) 100;
    totalamount=principal*pow(1+(rate/n),n*time);
    compoundInterest = totalamount-principal;
    printf("Hello %s",name);
    printf("\nThe compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is %.2f\n",principal,rate*100,n,time,compoundInterest);
    printf("Total is: %.2f",totalamount);
    
    return 0;
}
