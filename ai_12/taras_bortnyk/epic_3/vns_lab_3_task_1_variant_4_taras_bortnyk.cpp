#include <iostream>
#include <cmath>
#include <iomanip>

double calculateSum(double x) {
    double sum = 0;

    for (int i = 1; i <= 10; ++i) {
        sum += std::pow(x, i) / std::sqrt(i);
    }

    return sum;
}

double computeSeries(double x, double eps) {
    double result = 0;
    double term = x;
    int i = 1;

    while (std::fabs(term) > eps) {
        result += term;
        ++i;
        term = -term * x * x / (2 * i - 1) / (2 * i);
    }

    return result;
}

double evaluateFunction(double x) {
    return std::sin(x) + std::cos(x);
}

int main() {
    double epsilon = 0.0001;

    for (double val = 0.1; val <= 0.8; val += 0.1) {
        std::cout << "Value = " << val;
        std::cout << " Sum = " << calculateSum(val);
        std::cout << " Series = " << std::fixed << std::setprecision(4) << computeSeries(val, epsilon);
        std::cout.unsetf(std::ios_base::floatfield);
        std::cout << " Function = " << evaluateFunction(val) << std::endl;
    }

    return 0;
}
