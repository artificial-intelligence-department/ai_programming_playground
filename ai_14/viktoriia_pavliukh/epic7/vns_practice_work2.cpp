#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Задані значення констант та змінних
    int a = 2, b = 3, c = 7;
    double h = 0.31, y, x;

    // Цикл для ітерації від 0 до 5 з кроком h
    for (x = 0; x <= 5; x += h) {
        // Умовна конструкція для розрахунку значення y в залежності від значення x
        if (x < 2) {
            // Якщо x менше 2
            y = pow(a, b - x) + c;
        } else if (x >= 2 && x <= 4) {
            // Якщо x більше рівне 2 і менше рівне 4
            y = pow(b, c - x) + a;
        } else if (x > 4) {
            // Якщо x більше 4
            y = pow(c, a - x) + b;
        }

        // Виведення значення y для кожного x
        cout << "For x = " << x << ", y = " << y << endl;
    }

    return 0;
}