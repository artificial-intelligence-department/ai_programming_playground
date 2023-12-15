#include <iostream>
#include <cmath> 

int main() {

    int int_a = 1000;
    float float_b = 0.0001;

    float float_c = pow((int_a - float_b), 2);
    std::cout << "float_c=" << float_c << std::endl;

    float float_d = pow(int_a, 2);
    std::cout << "float_d=" << float_d << std::endl;

    float float_e = (2 * int_a * float_b);
    std::cout << "float_e=" << float_e << std::endl;

    float float_f = pow(float_b, 2);
    std::cout << "float_f=" << float_f << std::endl;

    float float_result = (float_c - (float_d - float_e)) / float_f;
    std::cout << "result for float=" << float_result << std::endl;


    int int_a = 1000;
    double double_b = 0.0001;

    double double_c = pow((int_a - double_b), 2);
    std::cout << "double_c=" << double_c << std::endl;

    double double_d = pow(int_a, 2);
    std::cout << "double_d=" << double_d << std::endl;

    double double_e = (2 * int_a * double_b);
    std::cout << "double_e=" << double_e << std::endl;

    double double_f = pow(double_b, 2);
    std::cout << "double_f=" << double_f << std::endl;

    double double_result = (double_c - (double_d - double_e)) / double_f;
    std::cout << "result for double=" << double_result << std::endl;

    return 0;
}
