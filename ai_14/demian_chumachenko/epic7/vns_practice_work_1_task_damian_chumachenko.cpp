#include <iostream>
#include <cmath>
//v-11
int main() {
    double x = 1.25, y = 0.93; // intializing x and y

    double a = (1 - y) * (pow(x + y, 2) / pow(x + 4, 3)) / (exp(2 - x) + (pow(x, 3) + 4)); // formula for a
    double b = (1 + cos(y - 2)) / (pow(x, 2) + pow(sin(y - 2), 2)); // formula for b

    double p = a / b;

    std::cout << "p = " << p << std::endl;
    
    return 0;
}