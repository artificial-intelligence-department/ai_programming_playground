#include <iostream>
#include<cmath>
int main() {
    
    std::cout << "Введіть значення m : ";
    double m_double;
    std::cin >> m_double;

    std::cout << "Введіть значення n : ";
    double n_double;
    std::cin >> n_double;

    
    double result_double = --m_double - ++n_double;


    std::cout << "Результат : " << result_double << std::endl;



    return 0;
}
