#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    float a, b, c, d;
    a = 1000;
    b = 0.0001;
    d = (6 * a * b - 2 * pow(b, 2)) / (pow(b, 2) - 3 * pow(a, 2));
    c = 1 + d;
    std::cout << "результат виразу 1: " << std::fixed << std::setprecision(45) << c << std::endl;

    double a1, b1, c1, d1;
    a1 = 1000;
    b1 = 0.0001;
    d1 = (6 * a1 * b1 - 2 * pow(b1, 2)) / (pow(b1, 2) - 3 * pow(a1, 2));
    c1 = 1 + d1;
    std::cout << "результат виразу 2: " << std::fixed << std::setprecision(60) << c1 << std::endl;

    return 0;
}

