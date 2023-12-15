#include <iostream>
#include <math.h>

int main() {
    double a_double, b_double;
    float a_float, b_float;

    std::cout << "Enter a and b\n";
    std::cin >> a_double >> b_double;

    a_float = static_cast<float>(a_double);
    b_float = static_cast<float>(b_double);

    double x_double, g_double, f_double, c_double, d_double;

    g_double = pow((a_double - b_double), 3);
    f_double = pow(a_double, 3);
    c_double = pow(b_double, 3);
    d_double = 3 * a_double * pow(b_double, 2);

    x_double = (g_double - f_double) / (c_double - d_double - 3 * pow(a_double, 2) * b_double);

    std::cout << "double: " << x_double << std::endl;

    float x_float, g_float, f_float, c_float, d_float;

    g_float = pow((a_float - b_float), 3);
    f_float = pow(a_float, 3);
    c_float = pow(b_float, 3);
    d_float = 3 * a_float * pow(b_float, 2);

    x_float = (g_float - f_float) / (c_float - d_float - 3 * pow(a_float, 2) * b_float);

    std::cout << "float: " << x_float << std::endl;

    return 0;
}