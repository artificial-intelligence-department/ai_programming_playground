#include <iostream>
#include <cstdarg> //для роботи зі змінною кількістю аргументів

using namespace std;

// Функція для обчислення суми звичайних дробів зі змінною кількістю параметрів
double sum(int count, ...) {
    va_list args;
    double sum = 0;

    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, double);
    }
    va_end(args);

    return sum;
}

int main() {
    // Виклики функції sum зі змінною кількістю параметрів
    double result1 = sum(5, 1.5, 2.0, 3.5, 4.0, 5.5);
    double result2 = sum(10, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1);
    double result3 = sum(12, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.1, 11.2, 12.3);

    
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;

    return 0;
}
