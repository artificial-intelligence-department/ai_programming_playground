#include <iostream>
#include <iomanip>
#include <cmath>

double calculateCoefficient(int n, double x) {
    return (2 * n + 1) * pow(x, 2 * n) / tgamma(n + 1);
}

double calculateSN(int n, double x) {
    double SN = 1; // Перший член ряду

    for (int i = 1; i <= n; ++i) {
        SN += calculateCoefficient(i, x);
    }

    return SN;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    double epsilon = 0.0001; // Задана точність epsilon
    int n = 10; // Заданий n для розкладу

    std::cout << "Обчислення функції" << std::endl;
    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i <= k; ++i) {
        double x = a + (b - a) * i / k;

        double SE = 1.0;
        double term = 1.0;
        int currentN = 1;

        while (std::abs(term) > epsilon && currentN <= n) {
            term = calculateCoefficient(currentN, x);
            SE += term;
            currentN++;
        }

        double SN = calculateSN(n, x); // SN для заданого n
        double exactValue = (1 + 2 * x * x) * exp(x * x); // Точне значення функції

        std::cout << "X=" << x << " SN=" << SN << " SE=" << SE << " Y=" << exactValue << std::endl;
    }

    return 0;
}
