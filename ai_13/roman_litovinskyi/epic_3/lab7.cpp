#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// Функція для перевірки, чи точка (x, y) знаходиться всередині кола радіусом R
int pointInCircle(double x, double y, double R) {
    double distance = sqrt(x * x + y * y); // Обчислюємо відстань від точки до центру кола
    return distance <= R; // Перевіряємо, чи точка знаходиться всередині кола (відстань <= радіусу)
}

// Функція для підрахунку кількості точок, які належать колу з радіусом R
int belong(int R, int numPoints, ...) {
    int count = 0; // Лічильник кількості точок, що належать колу

    va_list args;
    va_start(args, numPoints); // Ініціалізація доступу до аргументів

    for (int i = 0; i < numPoints; i++) {
        double x = va_arg(args, double); // Отримання координати x
        double y = va_arg(args, double); // Отримання координати y

        if (pointInCircle(x, y, R)) { // Перевірка, чи точка знаходиться в колі
            count++; // Якщо так, збільшуємо лічильник
        }
    }

    va_end(args); // Завершення роботи з аргументами

    return count; // Повертаємо кількість точок, які належать колу
}

int main() {
    int R = 100; // Радіус кола

    // Підрахунок кількості точок, які належать колу для різної кількості аргументів
    int count1 = belong(R, 3, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
    printf("Number of points belonging to the circle with 3 parameters: %d\n", count1);

    int count2 = belong(R, 5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    printf("Number of points belonging to the circle with 9 parameters: %d\n", count2);

    int count3 = belong(R, 6, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
    printf("Number of points belonging to the circle with 11 parameters: %d\n", count3);

    return 0; 
}
