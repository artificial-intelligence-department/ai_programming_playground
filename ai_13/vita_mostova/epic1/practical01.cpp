#include <cstdio>
#include <cmath>
#include <iostream>
int main() {
        double p;  //оголошення змінних
        double r;
        int t;
        int n;
        

        char name[32];

        printf("Enter your name:\n");   //введення даних 
        scanf("%s",name);
        printf("Enter your principal amount:\n");
        scanf("%lf", &p);
        printf("Enter the rate of interest (in percentage):\n");
        scanf("%lf",&r);
        printf("Enter the number of years:\n");
        scanf("%d",&t);
        printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):\n");
        scanf("%d",&n);
        double A=p*pow((1+r/(100*n)),n*t);  //формула складних відсотків
        double A1=A-p;
        printf("Hello, %s !\n",&name);     //виведення результатів
        printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p,r,n,t,A1);
        printf("The total amount after %d years is:%.2f\n",t,A);
        
        return 0;

    }