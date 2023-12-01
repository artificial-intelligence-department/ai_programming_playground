#include <stdio.h>
#include <math.h>

int main() {
    char name[100];
    int P, n, t;
    double r;

    printf("Введіть ваше ім'я \n");
    scanf("%s", &name);

    printf("Основна сума інвестиції: ");
    scanf("%d", &P);

    printf("Річна процентна ставка: ");
    scanf("%lf", &r);
    r = r / 100;

    printf("Кількість нарахувань відсотків на рік: ");
    scanf("%d", &n);

    printf("Час, на який гроші інвестуються, у роках: ");
    scanf("%d", &t);

    double A = P * pow((1 + r / n), n * t); // Формула обчислення складних відсотків за депозитом

    printf("%s, Ваша загальна сума інвестиції: %.2lf", name, A);

    return 0;
}
