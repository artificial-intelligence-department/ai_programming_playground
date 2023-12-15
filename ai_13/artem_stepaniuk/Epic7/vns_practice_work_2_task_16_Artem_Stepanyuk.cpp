#include <iostream>
#include <cmath>

// Це функція для розрахунку значення функції залежно від умови
double calculateFunction(double x, double a) {
    return (x > 2) ? cos(a * x + 2) : tan(fabs(x - 2 * a));
}

// Вот тут функція повинна вивести результат
void printResult(double x, double y) {
    std::cout << "For x = " << x << ", y = " << y << std::endl;
}

int main() {
    // Це задані задачею значення
    double x_values[] = {0, 5, 3, 1};
    double h_x = 0.2;
    double a = 0.1;
    double h_a = 0.3;

    // Тут розрахунок та виведення значень для кожної Х
    for (double x : x_values) {
        double result = calculateFunction(x, a);
        printResult(x, result);
    }

    // Зміна a з кроком h_a та виведення результатів
    while (a <= 5) {
        double result = calculateFunction(x_values[0], a);
        printResult(a, result);

        // Зміна a
        a += h_a;
    }

    return 0;
}
