#include <iostream>
#include <cmath>


int main() {
    // Задані значення параметрів
    const double m = 2.0;
    const double c = 1.0;
    const double x = 1.2;
    const double b = 0.7;

    // Обчислення значення функції фі
    double phi = sqrt(m * tan(x) + fabs(c * sin(x)));

    // Обчислення значення функції ета
    double eta = m * cos(b * x + sin(x)) + c * pow(sin(x), 3);

    // Виведення результатів
    std::cout << "Phi: " << phi << std::endl;
    std::cout << "Eta: " << eta << std::endl;

     

    return 0;
}
