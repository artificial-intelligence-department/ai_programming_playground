#include <iostream>
#include <cmath>

int main() {
    double x = 0.3;  
    double a = 0.5; 
    double b = 2.9; 

   
    double U = pow(a, 3) + exp(-x) * cos(x) / (b * x - exp(-x) * sin(b * x) + 1);
    std::cout << "U: " << U << std::endl;

   
    double f = exp(2 * x) * log(a + x) - pow(b, 3) * log(fabs(x - b));
    std::cout << "f: " << f << std::endl;

    return 0;
}