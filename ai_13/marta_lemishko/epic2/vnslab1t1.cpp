#include <iostream>
#include <cmath>

int main() {
    double a = 1000;
    double b = 0.0001;
    
    double result = std::pow(a + b, 3) - (std::pow(a, 3) / (3 * a * b * b)) + std::pow(b, 3) + 3 * a * a * b;
    
    std::cout << "Результат розрахунку: " << result << std::endl;
    
    return 0;
}