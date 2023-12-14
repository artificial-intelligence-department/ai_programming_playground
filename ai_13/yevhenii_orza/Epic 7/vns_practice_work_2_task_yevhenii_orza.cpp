#include <iostream>
#include <cmath>

int main() {
     // Задані значення параметрів
    const double a = 2.4;
    const double step = 0.5;

    // Обчислення значень функції z для кожного x
    for (double x = -3.0; x <= 3.0; x += step) {
        // Уникнення ділення на нуль, якщо x = -1
        double denominator = (x == -1.0) ? 0.000001 : x + 1;

        double z = (cos(x) - 1) / denominator;

        // Обчислення значення h(x)
        double hx = 0.5 * a;

        // Виведення результатів
        std::cout << "x = " << x << ", z = " << z << ", h(x) = " << hx << std::endl;
    }
       

    return 0;
}
