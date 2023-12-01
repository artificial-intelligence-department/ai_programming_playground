#include <stdio.h>

int main() {
    char name[50];
    float principle, rate, time;
    double compound_interest;

    printf("Введіть ваше ім'я: ");
    gets (name);

    printf("Введіть принцип (початкову суму): ");
    scanf("%f", &principle);

    printf("Введіть ставку відсотків (у відсотках): ");
    scanf("%f", &rate);

    printf("Введіть час (в роках): ");
    scanf("%f", &time);

  compound_interest = principle *((1 + rate), time);

    printf("%s, ваші складні відсотки становлять: %.2lf\n", name, compound_interest);

    return 0;
}