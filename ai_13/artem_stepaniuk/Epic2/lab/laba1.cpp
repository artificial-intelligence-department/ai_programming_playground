#include <iostream>

int main() {
    int n = 5;
    int m = 3;
    
    int result_int = n++ * m;
    
    std::cout << "Result (int): " << result_int << std::endl;

    float n_float = 5.0f;
    float m_float = 3.0f;
    
    float result_float = n_float++ * m_float;
    
    std::cout << "Result (float): " << result_float << std::endl;

    double n_double = 5.0;
    double m_double = 3.0;
    
    double result_double = n_double++ * m_double;
    
    std::cout << "Result (double): " << result_double << std::endl;

    return 0;
}
