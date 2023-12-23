#include <iostream>
#include <cmath>

int main() {
    double a = 1.1;
    double b = 0.004;
    double x = 0.2;

    double y = pow(sin(a * a), 3) - pow(sqrt(x / b), 3);
    double z = pow(x, 2) / (a + pow(cos(x + b), 2));

    std::cout << "Значення y: " << y << std::endl;
    std::cout << "Значення z: " << z << std::endl;

    return 0;
}