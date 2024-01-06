#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Створюємо дійсну змінну з подвійною точністю константу e - експонента, використовуючи функцію exp() бібліотеки cmath
    // Вимога 3, 4
    const double e = exp(1);

    // Створюємо дійсні змінні константи для чисел a, b, c
    // Вимога 2
    const float a = 0.5;
    const float b = 3.1;
    const float x = 1.4;

    // Створюємо і обчислюємо дійсну змінну з подвійною точністю alpha заповнюючи її формулою з використаням функцій: sqrt, abs, pow, sin
    // Вимога 16, 17
    double alpha = sqrt(abs(a * pow(x, 2) * sin(2 * x) + pow(e, -2 * x) * (x + b)));
    // Вивести змінну alpha
    cout << alpha << "\n";

    // Створюємо і обчислюємо дійсну змінну з подвійною точністю omega заповнюючи її формулою з використаням функцій: pow, cos, cbrt
    double omega = 1 / (pow(cos(pow(x, 3)), 2)) - x / (cbrt(pow(a, 2) + pow(b, 2)));
    // Вивести змінну omega
    cout << omega << "\n";

    return 0;
}