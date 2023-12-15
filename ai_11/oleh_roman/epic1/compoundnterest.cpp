#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double p, y, f;
    char name[100];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Interest rate: ");
    scanf("%lf", &p);

    printf("Number of years: ");
    scanf("%lf", &y);

    printf("Initial contribution: ");
    scanf("%lf", &f);

    double profit = f * pow(1 + p / 100.0, y);

    printf("Dear %s, your profit after %.0lf years will be: %.2lf\n", name, y, profit);
    return 0;
}
