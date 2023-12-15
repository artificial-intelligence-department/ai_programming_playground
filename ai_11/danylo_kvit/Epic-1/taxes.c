#include <stdio.h>
#include <math.h>
int main() {
    char name[30];
    printf("Name: ");
    scanf("%s", name);

    float princ;
    printf("Principal amount: ");
    scanf("%f", &princ);

    float rate;
    printf("Rate of interest(in percent): ");
    scanf("%f", &rate);

    float years;
    printf("Years: ");
    scanf("%f", &years);

    float per;
    printf("Period: ");
    scanf("%f", &per);

    rate = rate/100;
    float result = princ*pow(1+(rate/per), per*years);
    float income = result - princ;

    printf("Hello %s \n", name);
    printf("The compound  interest for a principal of %f at a rate of %f compounded %f  times a tear is %f \n", princ,  rate*100, per, result);
    printf("Total income after %f years is: %.2f ", years, income);

    return 0;

}