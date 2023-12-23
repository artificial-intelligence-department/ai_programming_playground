#include <iostream>
#include <cmath>

double h_function(double x, double y) {
    double result;

    if (x > y) {
        result = (pow(x, 2)) / (pow((x - 5), 3));
    } else {
        result = (pow((x - 2), 3)) / (y * pow((x - 5), 4));
    }
    
    return result;
}

int main() {
    double x_value, y_value;
    
    std::cout << "Введіть значення x: ";
    std::cin >> x_value;
    std::cout << "Введіть значення y: ";
    std::cin >> y_value;

    double result_h = h_function(x_value, y_value);
    std::cout << "Значення h(x) для x = " << x_value << " та y = " << y_value << " дорівнює " << result_h << std::endl;

    return 0;
}