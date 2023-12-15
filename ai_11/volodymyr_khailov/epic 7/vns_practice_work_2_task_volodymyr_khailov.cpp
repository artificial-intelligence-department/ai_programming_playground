// Варіант 11
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 2. в коді використана як мінімум одна дійсна змінна
    float xFrom = 1.0;
    float xTo = 3.0;
    float hx = 0.1;
    
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int numOfSteps = (xTo - xFrom)/hx ;
    
    // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double aFrom = 1.0;
    double aTo = 5.0;
    double ha = (aTo - aFrom)/numOfSteps;

    // 4. в коді використана як мінімум одна цілочисельна константа
    const int b = 2;

    
    const int arraySize = numOfSteps + 1;
    // 6. в коді використаний одновимірний масив
    double x_values[arraySize];
    double a_values[arraySize];

    // Заповнення масивів x_values і a_values
    // 10. в коді використаний for цикл
    for (int i = 0; i < arraySize; ++i) {
        x_values[i] = xFrom + i * hx;
        a_values[i] = aFrom + i * ha;
    }

    // Виведення заголовка
    // 21. в коді використано оператори виведення та введення даних
    printf("%-10s%-10s%-10s\n", "x", "a", "y");
    printf("----------------------------------\n");

    // 10. в коді використаний for цикл
    for (int i = 0; i < arraySize; ++i) {
        // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
        double x = x_values[i];
        double a = a_values[i];
        double result;

        // 5. в коді використані умовні оператори та розгалуження
        // 17. в коді використано математичні операції та математичні функції
        if (x < double(b)) {
            result = sin(fabs(a * x + pow(b, a)));
        } else {
            result = cos(fabs(a * x - pow(b, a)));
        }

        // Виведення результатів з форматуванням
        // 21. в коді використано оператори виведення та введення даних
        printf("%-10.2f%-10.2f%-10.4f\n", x, a, result);
    }

    return 0;
}
