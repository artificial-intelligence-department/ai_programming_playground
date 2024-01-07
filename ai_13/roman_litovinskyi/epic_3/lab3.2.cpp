#include <iostream>
#include <cmath>

double calculateFunction(double x) {
    return exp(2 * x); // Функція y = e^(2x)
}

double calculateSeries(double x, int n) {
    double sum = 0; // Початкове значення суми

    for (int i = 1; i <= n; i++) {
        double term = pow(2 * x, i) / tgamma(i + 1); // Обчислення кожного члена ряду ((2x)^n)/n!
        sum += term; // Додавання члена до суми
    }

    return sum;
}

int main() {
    double lowerBound = 0.1; // Нижня межа аргументу
    double upperBound = 1.0; // Верхня межа аргументу
    int numberOfTerms = 10; // Кількість членів ряду

    std::cout << "The range of argument variation: " << lowerBound << " <= x <= " << upperBound << std::endl;
    // Цикл для обчислення значень функції та суми ряду для кожного x в заданому діапазоні
    for (double x = lowerBound; x <= upperBound; x += 0.1) {
        double functionValue = calculateFunction(x); // Обчислення значення функції
        double seriesSum = calculateSeries(x, numberOfTerms); // Обчислення суми ряду

        std::cout << "x = " << x << ", y = " << functionValue << ", sum= " << seriesSum << std::endl;
    }

    return 0;
}
