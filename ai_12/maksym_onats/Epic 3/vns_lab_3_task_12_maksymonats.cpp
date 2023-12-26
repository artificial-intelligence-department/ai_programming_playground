#include <iostream>
#include <cmath>

double calculateFunction(double x, int n) {
    double result = 0.0, term = 1.0;

    for (int i = 1; i <= n; ++i) {
        term *= (-1) * (2 * x * cos(M_PI/3) - x * x) / i;
        result += term;
    }

    return -0.5 * result;
}

double calculateFunctionWithPrecision(double x, double epsilon) {
    double result = 0.0, term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= (-1) * (2 * x * cos(M_PI/3) - x * x) / n;
        result += term;
        ++n;
    }

    return -0.5 * result;
}

int main() {
    double a = 15;
    double b = 1;
    int k = 10;
    int n = 3;
    double epsilon = 0.0001;

    for (int i = 0; i <= k; ++i) {
        double x = a + i * (b - a) / k;
        
        double resultN = calculateFunction(x, n);
        double resultEpsilon = calculateFunctionWithPrecision(x, epsilon);
        double exactValue = -0.5 * log(1 - 2 * x * cos(M_PI/3) + x * x);

        std::cout << "x = " << x << ", Result (n = " << n << ") = " << resultN
            << ", Result (epsilon = " << epsilon << ") = " << resultEpsilon
            << ", Exact Value = " << exactValue << '\n';
    }

    return 0;
}