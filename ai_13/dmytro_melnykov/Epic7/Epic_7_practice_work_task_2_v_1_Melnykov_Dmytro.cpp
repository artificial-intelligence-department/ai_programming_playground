#include <iostream>
#include <cmath>
#include <iomanip>

double Y(double x, double a, double b, double c) {
    if (x < 0.5) {
        return x * a + b * cos(x);
    } else if (0.5 < x && x <= 1) {
        return b * pow(x, 2) + c * sin(2 * x);
    }
}

int main() {
    double a = 0.75;
    double b = 1.19;
    double c = -2.5;

    for (double x = 1; x <= 2; x += 0.1) {
        double result = Y(x, a, b, c);
        std::cout << std::fixed << std::setprecision(4) << "x = " << x << ", Y = " << result << std::endl;
    }

    return 0;
}
