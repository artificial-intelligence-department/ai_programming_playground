#include <iostream>
#include <cmath>

// Функція для обчислення модулю числа
double module(double x) {
    return (x < 0) ? -x : x;
}

int main() {
    // Заданння значення константам
    double a = 10.2;
    double b = 9.3;
    double x = 2.4;
    double c = 0.5;

    // Обчислення виразу K
    double term1_K = log(a + pow(x, 3));   // ln(a + x^3)
    double term2_K = pow(sin(x / b), 2);   // sin^2(x/b)
    double K = term1_K + term2_K;

    // Виведення результату K
    std::cout << "Result K: " << K << std::endl;

    // Обчислення виразу M
    double term1_M = cbrt(x + a);   // Кубічний корінь (x + a)
    double term2_M = sqrt(abs(x - b));  // Квадратний корінь з модулю (x - b)
    double term3_M = exp(-c * x);          // e^(-cx)
    double term4_M = (x + term1_M) / (x - term2_M);  // (x + cbrt(x + a)) / (x - sqrt(|x - b|))

    double M = term3_M * term4_M;

    // Виведення результату M
    std::cout << "Result M: " << M << std::endl;

    return 0;
}
