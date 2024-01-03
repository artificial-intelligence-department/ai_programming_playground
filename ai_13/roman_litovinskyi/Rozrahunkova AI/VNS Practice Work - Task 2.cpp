#include <iostream>
#include <cmath>

int main() {
    double x;
    double h_x = 0.1;
    int count_negative = 0;

    // Для кожного x в інтервалі [0.3, 0.5] з кроком 0.1
    for (x = 0.3; x <= 0.5; x += h_x) {
        double y = cos(x * x) * exp(-x);

        if (y < 0) {
            count_negative++;
        }
    }

    std::cout << "Кількість випадків, коли функція приймає негативне значення: " << count_negative << std::endl;

    return 0;
}
