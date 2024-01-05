#include <iostream>
#include <cmath>

const double m = 2.0;
const double c = 1.0;
const double x = 1.2;
const double b = 0.7;

// Вимога 14 - в коді використано структури.
struct Output
{

    // Вимога 3 - в коді використана як мінімум одна дійсний щ подвійною точністтю змінна.
    double f;
    double e;
} Output1;

int main()
{
    // Вимога 17 - в коді використано математичні операції та математичні функції.
    Output1.f = sqrt(m * tan(x) + fabs(c * sin(x)));
    Output1.e = m * cos(b * x + sin(x)) + pow(c, 3);

    // Вимога 21 - в коді використано оператори введення та виведення даних.
    std::cout << "φ = " << Output1.f << std::endl;
    std::cout << "ξ = " << Output1.e << std::endl;

    return 0;
}