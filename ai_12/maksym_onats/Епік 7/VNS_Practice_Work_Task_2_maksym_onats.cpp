#include <iostream>
#include <cmath>

int main() {
    const double x_start = 0.3;
    const double x_end = 3.5;
    const double h = 0.1;
    int count = 0;

    for (double x = x_start; x <= x_end; x += h) {
        double y = cos(pow(x, 2)) * exp(-x);

        if (y < 0) {
            count++;
        }
    }

    std::cout << "The function y = cos(x^2) * e^(-x) takes a negative value " << count << " times between x = " << x_start << " and x = " << x_end << std::endl;

    return 0;
}