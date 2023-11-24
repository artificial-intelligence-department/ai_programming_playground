#include <stdio.h>
#include <math.h>

int main() {
    double sum;
    int time;
    double rate;
    double vid;
    char name[100]; 

    printf("Your name:");
    scanf("%s", name);
    printf("Please enter deposit amount: ");
    scanf("%lf", &sum);
    printf("Please enter amount of years: ");
    scanf("%d", &time);
    printf("Please enter percent rate: ");
    scanf("%lf", &rate);

    printf("%lf %d", sum * pow((1 + rate * 0.01), time), time);

    return 0;
}