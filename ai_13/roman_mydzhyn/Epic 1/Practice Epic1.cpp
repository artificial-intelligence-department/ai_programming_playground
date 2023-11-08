#include <Cstdio>
#include <cmath>

char name[100];
double rate, pricipal, amount, compoundInterest;
int years, period;

int main()
{
	printf("Enter your name \n");
	scanf("%s", &name);

	printf("Enter the pricipal amount:");
	scanf("%lf", &pricipal);

	printf("Enter the rate of interest:");
	scanf("%lf", &rate);

	printf("Enter the number of years:");
	scanf("%d", &years);

	printf("Enter the number of times the interest is compounded per year:");
	scanf("%d", &period);

	double amount = pricipal * pow(1 + rate / period, period * years);
	printf("the amount is %lf", amount);
	printf("\n");

	double compoundInterest = pricipal * pow(1 + rate / period, period * years) - pricipal;
	printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", pricipal, rate * 100, period, years, compoundInterest);

	return 0;
}
