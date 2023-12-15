#include <cstdio>
#include <cmath>

int main() {
  char name[50];
  double principal, rate, totalAmount, compoundInterest;
  int years, period;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your principal amount: ");
  scanf("%lf", &principal);

  printf("Enter the rate: ");
  scanf("%lf", &rate);

  printf("Enter the number of years: ");
  scanf("%i", &years);

  printf("Enter period: ");
  scanf("%i", &period);

  rate /= (double)100;

  totalAmount = principal * pow(1 + (rate / period), period * years);
  compoundInterest = totalAmount - principal;

  printf("Hello %s \n", name);
  printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, period, years, compoundInterest);
  printf("Total is %.2f", totalAmount);

  return 0;
}