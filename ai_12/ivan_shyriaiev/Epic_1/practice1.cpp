
#include<cstdio>
#include<cmath>
using namespace std;


int main(){
char name[50];
double principal, rate, total;
int time, n;
printf("Enter your name:\n");
scanf("%s", &name);

printf("enter the principal amount:\n");
scanf("%lf", &principal);

printf("enter the rate of interest:\n");
scanf("%lf", &rate);

    rate= rate/100;

printf("enter the number of years:\n");
scanf("%d", &time);

printf("enter the number of times interest is compouded per year(e.g., 1 for annually, 4 for quarterly, 12 for monthly: \n");
scanf("%d", &n);

    total= principal*pow(1+(rate/n), n*time);
    double compound = total - principal;

printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, time, compound);

        printf("total amount is %lf", total);
}