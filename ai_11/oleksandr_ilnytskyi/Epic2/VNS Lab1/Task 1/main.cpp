#include <iostream>
#include <cmath>

using namespace std;

float a = 100;
float b = 0.001;

float when_float(float x, float y) {
    float numerator = pow(x + y, 3) - (pow(x, 3) + 3 * pow(x, 2) * y);
    float denominator = 3 * x * pow(y, 2) + pow(y, 3);
    return numerator / denominator;
}

double when_double(double x, double y) {
    double numerator = pow(x + y, 3) - (pow(x, 3) + 3 * pow(x, 2) * y);
    double denominator = 3 * x * pow(y, 2) + pow(y, 3);
    return numerator / denominator;
}

int main() {
    float result_float = when_float(a, b);
    double result_double = when_double(a, b);

    printf("When floats result is: %f. When doubles result is: %f", result_float, result_double);

    return 0;
}
