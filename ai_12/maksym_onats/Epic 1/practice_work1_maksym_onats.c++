#include <cstdio>
#include <cmath>
#include <string>

int main() {
    char* name[50];
    double p, r, a, i;
    int t, c;

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("Hello, %s! \n", name);

    printf ( "Enter some data so we can calculate the compound interest\n" );

    printf("Enter your principal amount: ");
    scanf("%lf", &p);

    printf("Enter the rate of interests (in percentage): ");
    scanf("%lf", &r);

    printf("Enter the number of years: ");
    scanf("%d", &t);

    printf("Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ");
    scanf("%d", &c);

    r = r / 100;
    a = p * pow(1 + (r / c), c * t);
    i = a - p;

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p, r * 100, c, t, i);
    printf("The total amount after %d years is: %.2lf\n", t, a);
    printf("Thank you for using our program\n\n");

    return 0;
}