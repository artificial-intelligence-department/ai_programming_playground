#include <iostream>
#include <cmath>

double mtgx(double x) {
    return tan(x);
}

double csinx(double x) {
    return cos(x);
}

double linearAlgorithm(double x, double m, double c, double b) {
    double phi = sqrt(mtgx(x) + fabs(csinx(x)));
    double xi = m * cos(b * x + sin(x)) + pow(c, 3);

    return phi + xi;
}

int main() {
    double m = 2.0;
    double c = 1.0;
    double x = 1.2;
    double b = 0.7;

    double result = linearAlgorithm(x, m, c, b);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
