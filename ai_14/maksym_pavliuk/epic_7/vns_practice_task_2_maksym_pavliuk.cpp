#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Ініціалізація змінних
    double x = 0.3, y;
    int count = 0;

    // Цикл для обчислення функції та підрахунку від'ємних значень
    for (double i = 0.3; i <= 5; i = i + 0.1) {
        // Обчислення значення функції y = cos(i^2) * e^(-i)
        y = cos(pow(i, 2)) * pow(M_E, -1 * i);

        // Перевірка, чи отримане значення менше нуля
        if (y < 0) {
            count++;
        }
    }

    // Виведення кількості від'ємних значень
    cout << count << endl;

    return 0;
}
