#include <iostream>
#include <cmath>
int main() {
    // Задані значення констант
    const double b = 1.2;
    const double step_a = 0.5;
    const double step_x = 0.2;

    // Діапазон для a та x
    const double a_min = 0.5;
    const double a_max = 2.0;
    const double x_min = 0.0;
    const double x_max = 1.0;

    // Змінні для збереження значень a, x та y
    double a, x, y;

    // Вирішив зробити Вивід за допомогою таблиці
    std::cout << "a     |     x     |     y" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // Цикл для зміни значень a та x одночаснор
    for (a = a_min, x = x_min; a <= a_max || x <= x_max; a += step_a, x += step_x) {
        // Розрахунок функції для поточних значень a та x
        y = (4 * a * pow(x,2) + 37 * x + b) / (a - 0.5);  // Якщо знаменник при a = 0.5 , значення виразу знайти неможливо

        // Вивід значень у форматі таблиці
        std::cout << a << "     |     " << x << "     |     " << y << std::endl;
    }

    return 0;
}
