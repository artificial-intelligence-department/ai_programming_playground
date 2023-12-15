#include <iostream>

using namespace std;
int main()
{
  double principal, rate, compoundInterest;
  int n, years;
  char name[100];

  printf("Enter your name: ");
  scanf("%s", &name);

  printf("Enter principal: ");
  scanf("%lf", &principal);
  printf("Enter rate of interest (as a decimal): ");
  scanf("%lf", &rate);
  printf("Enter quantity of compounding: ");
  scanf("%d", &n);
  printf("Enter amount of years: ");
  scanf("%d", &years);

  printf("Hello %s\n", name);

  compoundInterest = principal;
  for (int i = 0; i < n * years; i++)
    compoundInterest = compoundInterest * (1 + rate);

  compoundInterest = compoundInterest - principal;

  printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, years, compoundInterest);
  return 0;
}
