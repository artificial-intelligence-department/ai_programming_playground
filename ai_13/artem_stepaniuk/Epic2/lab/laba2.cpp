#include <iostream>

int main() {
    // Приклад для цілих чисел
    int n = 5;
    int m = 3;
    
    bool result_2 = n++ < m;
    bool result_3 = n-- > m;
    
    std::cout << "Result 2 (int): " << result_2 << std::endl;
    std::cout << "Result 3 (int): " << result_3 << std::endl;

    // Приклад для дійсних чисел
    float n_float = 5.0f;
    float m_float = 3.0f;
    
    bool result_2_float = n_float++ < m_float;
    bool result_3_float = n_float-- > m_float;
    
    std::cout << "Result 2 (float): " << result_2_float << std::endl;
    std::cout << "Result 3 (float): " << result_3_float << std::endl;

    double n_double = 5.0;
    double m_double = 3.0;
    
    bool result_2_double = n_double++ < m_double;
    bool result_3_double = n_double-- > m_double;
    
    std::cout << "Result 2 (double): " << result_2_double << std::endl;
    std::cout << "Result 3 (double): " << result_3_double << std::endl;

    return 0;
}
