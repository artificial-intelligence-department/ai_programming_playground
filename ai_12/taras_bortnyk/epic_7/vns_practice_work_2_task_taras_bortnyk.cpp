#include <iostream>
#include <cmath>
#include <iomanip>

double calculateFunction(double x, double a) {
    double y;

    if (x > 2) {
        y = cos(a * x + 2);
    } else {
        double tg_value = tan(fabs(x - 2 * a));
        y = tg_value;
    }

    return y;
}

int main() {
    const double lower_limit = 0.5;
    const double upper_limit = 3.1;
    const double hx = 0.2;
    const double ha = 0.3;
    double a = 0.1;

    for (double x = lower_limit; x <= upper_limit; x += hx) {
        double result = calculateFunction(x, a);

        // Перевірка на валідність результату
        if (std::isnan(result)) {
            std::cout << "For x = " << x << ", y is undefined" << std::endl;
        } else {
            std::cout << "For x = " << std::fixed << std::setprecision(4) << x << ", y = " << result << std::endl;
        }
    }

    return 0;
}
