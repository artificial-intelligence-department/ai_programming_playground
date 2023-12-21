#include <iostream>
#include <cmath>

int main() {
   
    std::cout << "Введіть значення m : ";
    double m_double;
    std::cin >> m_double;

    std::cout << "Введіть значення n : ";
    double n_double;
    std::cin >> n_double;


    double temp_m_double = m_double++;
    double temp_n_double = n_double--;


    bool result_double = temp_n_double > temp_m_double;

    
    std::cout << "Результат виразу : " << result_double << std::endl;

    return 0;
}
