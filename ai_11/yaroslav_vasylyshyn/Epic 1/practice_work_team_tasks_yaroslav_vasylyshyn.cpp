#include <iostream>
#include <math.h>
using namespace std;
 int main(){
    double sum,rate,profit,totalsum;
    int numofyears, timesperyear;
    char name[20];
    
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &sum);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &numofyears);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d", &timesperyear);

    totalsum=(sum*pow(1+(rate/(100*timesperyear)),(numofyears*timesperyear)));
    profit=totalsum-sum;

    printf("Hello,%s!\nThe compound interest for a principal of %.2lf at a rate of %.2lf%% \ncompounded %d times a year for %d years is: %.2lf\nThe total amount after %d years is: %.2lf",name , sum, rate, timesperyear, numofyears, profit, numofyears,totalsum);
    return 0;
 }