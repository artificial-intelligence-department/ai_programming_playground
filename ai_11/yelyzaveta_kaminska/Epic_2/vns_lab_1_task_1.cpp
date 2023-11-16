#include <iostream> 
#include <cmath> 
 
int main() { 
    float a = 1000.0f; 
    float b = 0.0001f; 
 
    float result_float; 
 
    float f_1 = pow(a - b, 3); 
    float f_2 = pow(a, 3); 
    float f_3 = pow(b, 3); 
    float f_4 = 3 * a * pow(b, 2); 
    float f_5 = 3 * pow(a, 2) * b; 
 
    result_float = (f_1 - f_2) / (f_3 - f_4 - f_5); 
 
    std::cout << "Result for float: " << result_float << std::endl; 

    double c = 1000.0;
    double d = 0.0001;
 
    double result_double; 
 
    double d_1 = pow(c - d, 3); 
    double d_2 = pow(c, 3); 
    double d_3 = pow(d, 3); 
    double d_4 = 3 * c * pow(d, 2); 
    double d_5 = 3 * pow(c, 2) * d; 
 
    result_double = (d_1 - d_2) / (d_3 - d_4 - d_5); 
 
    std::cout << "Result for double: " << result_double << std::endl; 
 
    return 0; 
}
