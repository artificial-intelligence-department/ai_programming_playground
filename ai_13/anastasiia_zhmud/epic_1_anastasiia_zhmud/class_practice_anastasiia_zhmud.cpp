#include <cstdio>
#include <cmath>
int main(){
    char name[20];
    double P, r, rez;
    int t, n;
    printf("Enter your name:");
    scanf("%s", name);
    printf("Enter the principal amount:");
    scanf("%lf", &P);
    printf("Enter the rate of interest (in percentage):");
    scanf("%lf", &r);
    printf("Enter the number of years:");
    scanf("%d", &t);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly)");
    scanf("%d", &n);
    r=r/100;
    rez=P*pow(1+r/n, n*t);
    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", P, r*100, n, t, rez);
}