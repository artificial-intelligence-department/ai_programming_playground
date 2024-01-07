#include <iostream>
#include <cstdarg>

double calculateSum(int num, ...) {
    va_list values;
    double total = 0;

    va_start(values, num);
    for (int index = 0; index < num; ++index) {
        total += va_arg(values, double);
    }
    va_end(values);

    return total;
}

int main() {
    double sum1 = calculateSum(5, 1.5, 2.0, 3.5, 4.0, 5.5);
    double sum2 = calculateSum(10, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1);
    double sum3 = calculateSum(12, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.1, 11.2, 12.3);

    std::cout << "Sum 1: " << sum1 << std::endl;
    std::cout << "Sum 2: " << sum2 << std::endl; 
    std::cout << "Sum 3: " << sum3 << std::endl;

    return 0;
}
