#include <iostream>
#include <cmath>

int main() {
    // Присвоюємо значення константам
    double const a = 1.7, b = 2.3;

    // Перебираємо значення x від -1 до 1 з кроком 0.9
    for (double x = -1; x <= 1; x += 0.9) {
        // Перебираємо значення y від -2 до 2 з кроком 1
        for (double y = -2; y <= 2; y += 1) {
            double z;
            // Перевіряємо умову x*y > 0
            if (x * y > 0) {
                // Обчислюємо z за формулою ln(sqrt(a*(x^2)+b*(y^3))
                z = log(sqrt(a * pow(x, 2) + b * pow(y, 3)));
            } else {
                // Обчислюємо z за формулою (a^x)+(b^y)
                z = pow(a, x) + pow(b, y);
            }
            // Виводимо результат
            std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
        }
    }
    return 0;
}
