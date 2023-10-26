#include <cstdio>
#include <cmath>

int main(){
    char NAME[50];
    double PRINCIPAL;
    double RATE;
    int YEARS;
    int PERIOD;
    double OUTPUT;
    double TOTAL_AMOUNT;

    printf("Enter your name: ");
    scanf("%49[^\n]",NAME);
    printf("Enter the principal amount: ");
    scanf("%lf",&PRINCIPAL);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf",&RATE);
    printf("Enter the number of years: ");
    scanf("%d",&YEARS);
    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d",&PERIOD);

    RATE /= 100; 
    TOTAL_AMOUNT = PRINCIPAL * pow(1 + RATE/PERIOD, PERIOD*YEARS);
    OUTPUT = TOTAL_AMOUNT - PRINCIPAL;

    printf("%.2f\n", OUTPUT);
    printf("Hello, %s The compound interest for a principal of %.2f at a rate of %.2f %% compounded %d times a year for %d years is: %.2f\n", NAME, PRINCIPAL, RATE, PERIOD, YEARS, OUTPUT);
    printf("The total amount after %d years is: %.2f", YEARS, TOTAL_AMOUNT);
    return 0;
}