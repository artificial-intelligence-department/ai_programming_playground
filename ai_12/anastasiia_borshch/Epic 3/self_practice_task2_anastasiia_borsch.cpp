#include <iostream>
#include <cmath>

double powerOrSqrt(double base, int exponent) {
    if (exponent == -1) {
        return sqrt(base);
    } else {
        return pow(base, exponent);
    }
}

int main() {
    double base;
    int exponent;

    std::cout << "Enter number: ";
    std::cin >> base;

    std::cout << "Enter the exponent: ";
    std::cin >> exponent;

    double result = powerOrSqrt(base, exponent);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
