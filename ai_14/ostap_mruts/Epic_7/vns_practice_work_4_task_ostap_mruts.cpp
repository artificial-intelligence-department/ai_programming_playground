#include <iostream>
#include <cmath>

double absolute_value(double x) {
    return std::abs(x);
}

int main() {
    double start = -4.0;
    double end = 4.0;
    double step = 0.5;

    std::cout << " x   |   y=|x|\n";

    for (double x = start; x <= end; x += step) {
        double y = absolute_value(x);
        std::cout << x << " " << y << "\n";
    }

    return 0;
}