#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    double percent, years, sum;
    char name[100];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Interest rate: ");
    scanf("%lf", &percent);

    printf("Number of years: ");
    scanf("%lf", &years);

    printf("Enter the start capital: ");
    scanf("%lf", &sum);

    double result = sum * pow((1 + percent * 0.01), years);

    printf("Hello %s! Your profit after %.0lf years will be: %.2lf\n", name, years, result);

    return 0;
}
