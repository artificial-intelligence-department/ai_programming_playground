#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Таблиця значень функції y = |x|:" << endl;
    cout << "x\t|y|" << endl;

    // Цикл для аргументів від -4 до 4 з кроком 0.5
    for (double x = -4.0; x <= 4.0; x += 0.5) {
        double y = abs(x); // Обчислення значення функції для даного x

        // Виведення значень x та |y| в таблицю
        cout << x << "\t" << y << endl;
    }

    return 0;
}
