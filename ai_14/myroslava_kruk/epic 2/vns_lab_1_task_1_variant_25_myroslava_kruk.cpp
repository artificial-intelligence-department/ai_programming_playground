#include <iostream>
#include <cmath>

int main() {
    float a_float, b_float;
    double a_double, b_double;

  
    std::cout << "Введіть значення a (float): ";
    std::cin >> a_float;

    std::cout << "Введіть значення b (float): ";
    std::cin >> b_float;


    std::cout << "Введіть значення a (double): ";
    std::cin >> a_double;

    std::cout << "Введіть значення b (double): ";
    std::cin >> b_double;

   
    float result_float = pow(a_float + b_float, 3) - (pow(a_float, 3) - 3 * a_float * a_float * b_float) / (pow(b_float, 3) - 3 * a_float * b_float * b_float) - 3 * a_float * b_float * b_float;

    double result_double = pow(a_double + b_double, 3) - (pow(a_double, 3) - 3 * a_double * a_double * b_double) / (pow(b_double, 3) - 3 * a_double * b_double * b_double) - 3 * a_double * b_double * b_double;

   
    std::cout << "Результат для float: " << result_float << std::endl;
    std::cout << "Результат для double: " << result_double << std::endl;

    return 0;
}
