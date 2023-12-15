#include <iostream>
#include <cmath>

int main() {
    float a_float = 100.0f;
    float b_float = 0.001f;

    double a_double = 100.0;
    double b_double = 0.001;

    float result_float;
    float intermediate_float = std::pow((a_float - b_float), 4) - (std::pow(a_float, 4) - 4 * std::pow(a_float, 3) * b_float);
    result_float = intermediate_float / (6 * std::pow(a_float, 2) * std::pow(b_float, 2) - 4 * a_float * std::pow(b_float, 3) + std::pow(b_float, 4));

    double result_double;
    double intermediate_double = std::pow((a_double - b_double), 4) - (std::pow(a_double, 4) - 4 * std::pow(a_double, 3) * b_double);
    result_double = intermediate_double / (6 * std::pow(a_double, 2) * std::pow(b_double, 2) - 4 * a_double * std::pow(b_double, 3) + std::pow(b_double, 4));

    std::cout << "Result for float: " << result_float << std::endl;
    std::cout << "Result for double: " << result_double << std::endl;

    return 0;
}
