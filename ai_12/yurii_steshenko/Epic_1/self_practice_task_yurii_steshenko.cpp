#include <cstdio>
#include <cmath>
#include <math.h>

int main()
{
    // задаємо усі змінні
    char name[100];
    int years, period;
    double rate, pricipal, A;

    // дізнаємося у користувача змінні
    printf("Enter your name: ");
    scanf("%99[^\n]", name);

    // scanf працює по вказівниках
    // тому ми передаєм адресу змінних використовуючи &

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter your period: ");
    scanf("%d", &period);

    printf("Enter your rate: ");
    scanf("%lf", &rate);

    printf("Enter your pricipal: ");
    scanf("%lf", &pricipal);

    // обрахунок формули
    rate = rate / 100; // отримуємо відсотки

    A = pricipal * pow(1 + (rate / period), period * years);
    printf("Hello, %s!\n", name);
    printf("Your income: %.2f", A);

    return 0;
}
