#include <iostream>
#include <iomanip> // Додано для того щоб я зміг використовувати setprecision

using namespace std;

int main() {
    cout << setw(5) << "x" << " | " << setw(8) << "y" << endl; // Встановлення ширини полів для x та y

    // Лінія-роздільник таблиці
    cout << "-----------------\n";

    // Задані параметри функції
    double a = -2.4, b = 5, c = -3;

    // Діапазон та крок
    double start = -2, end = 2, step = 0.5;

    // Цикл для обчислення та виведення значень функції
    for (double x = start; x <= end; x += step) {
        double y = a * x * x + b * x + c;

        // Форматування та вивід значень x та y
        cout << fixed << showpoint << setprecision(2);
        cout << setw(5) << x << " | " << setw(8) << y << endl;
    }

    return 0;
}
