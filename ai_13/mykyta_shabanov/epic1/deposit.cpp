#include <stdio.h>

int main() {
    //start
  char name[32];
  double deposit, percentage, accrued = 0.0;
  int date, years;

  //prompting
  printf("Enter your name: ");
  scanf("%s", name);
  
  printf("\nEnter the principal amount: ");
  scanf("%lf", &deposit);
  
  printf("\nEnter the rate of interest (in percentage): ");
  scanf("%lf", &percentage);
  percentage /= 100.0;
  
  printf("\nEnter the number of years: ");
  scanf("%d", &years);
  
  printf("\nEnter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
  scanf("%d", &date);
  
  //main logic
  for(int i = 0; i < years * date; i++)
      accrued += (deposit + accrued) * percentage;
  
    //output
  printf("\nHello, %s", name);
  printf("\nThe compound interest for a principal of %.2lf at a rate %.2lf%% compounded %d times a year for %d years is %.2lf\n", deposit, percentage*100, date, years, accrued);
  
  return 0;
}