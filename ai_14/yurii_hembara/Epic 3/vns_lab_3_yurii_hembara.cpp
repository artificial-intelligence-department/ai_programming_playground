#include <iostream>
#include <cmath>

// Факторіал
int fact(int n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

double f(double x) {
    return cos(x); // Точна функція y = cos(x)
}

// Розклад в степеневий ряд
double powerSeriesN(double x, int n) {
    double result = 0.0;
    for (int i = 0; i <= n; ++i) {
        result += std::pow(-1, i) * std::pow(x, 2 * i) / static_cast<double>(fact(2 * i));
    }
    return result;
}

// Розклад в степеневий ряд з заданою точністю епсилон
double powerSeriesEpsilon(double x, double epsilon) {
    double result = 0.0;
    int i = 0;
    while (true) {
        double term = std::pow(-1, i) * std::pow(x, 2 * i) / static_cast<double>(fact(2 * i));
        result += term;
        if (std::abs(term) < epsilon) {
            break;
        }
        ++i;
    }
    return result;
}

int main() {
    double a = 0.0;  // Початок діапазону
    double b = 1.0;  // Кінець діапазону
    int k = 10;      // Кількість кроків
    int n = 5;       // Задане n
    double epsilon = 0.0001; // Задана точність епсилону

    double step = (b - a) / k;
    for (double x = a; x <= b; x += step) {
        double exactValue = f(x);
        double valueN = powerSeriesN(x, n);
        double valueEpsilon = powerSeriesEpsilon(x, epsilon);

        std::cout << "x = " << x << ", Exact = " << exactValue << ", Approx (n=" << n << ") = " << valueN
                  << ", Approx (epsilon=" << epsilon << ") = " << valueEpsilon << std::endl;
    }

    return 0;
}
