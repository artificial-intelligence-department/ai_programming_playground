#include <iostream>
#include <cmath>
#include <iomanip>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    double epsilon = 0.0001;
    double sum = 0.0;
    double term = 0.0;
    int n = 0;

    do {
        term = static_cast<double>(factorial(n) * factorial(n)) / std::pow(2, n * 2);
        
        sum += term;
        
        n++;
    } while (term > epsilon);

    std::cout << "Сума ряду з точністю ε=0.0001: " << std::setprecision(10) << sum << std::endl;

    return 0;
}