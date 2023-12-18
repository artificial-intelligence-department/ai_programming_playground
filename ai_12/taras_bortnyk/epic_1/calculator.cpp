#include <cstdio>
#include <cmath>

int main() {
  char name[50];
  double capital, percentage, sumtotal, compoundInterest;
  int years, period;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your principal amount: ");
  scanf("%lf", &capital);

  printf("Enter the rate: ");
  scanf("%lf", &percentage);

  printf("Enter the number of years: ");
  scanf("%i", &years);

  printf("Enter period: ");
  scanf("%i", &period);

  percentage /= (double)100;

  sumtotal = capital * pow(1 + (percentage / period), period * years);
  compoundInterest = sumtotal - capital;

  printf("Hello %s \n", name);
  printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", capital, percentage * 100, period, years, compoundInterest);
  printf("Total is %.2f", sumtotal);

  return 0;
  
}