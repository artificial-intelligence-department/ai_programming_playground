#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon = 0.0001; // точність ε
    double sum = 0.0;
    double a = 1.0; // Початкове значення a
    int n = 1;

    while (true) {
        double factorial = 1.0;
        for (int i = 1; i <= n; ++i) {
            factorial *= i; // Обчислення факторіалу
        }

        a = factorial / pow(n, n); // Обчислення загального члена ряду a=(n!)/(n^n)

        if (a < epsilon) {
            break; // Вийти з циклу, якщо a стало меншим за ε
        }

        sum += a; // Додавання a до суми
        n++;
    }

    cout << "Сума ряду з точністю ε=" << epsilon << " : " << sum << endl;

    return 0;
}


