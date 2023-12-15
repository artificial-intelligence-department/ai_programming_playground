#include <iostream> // підключення бібліотеки для введення/виведення

using namespace std; // використання простору std для уникнення повторень в коді

int main() { // початок головної ф-ції 
    const int n = 10; // оголошення та ініціалізація константи, використано цілочисельну константу
    int x, y; // оголошення та ініціалізація типу змінних int, використано цілочисельні змінні
    int count_quarter[4] = {0}; //створено масив для підрахунку кількості точок у кожній чверті, використано цілочисельні змінні

    for (int i = 0; i < n; ++i) { //використано цикл for для введення координат 10 точок
        cout << "Введіть координати точки " << i + 1 << " (x y): "; // повідомлення для ввеення координат точок, використано оператор вивеення cout
        cin >> x >> y; //введення координат, використано оператор вивеення cin

        if (x > 0 && y > 0) { // визначення чверті та збільшення лічильника відповідної чверті, використано умовний оператор if
            count_quarter[0]++; // перша чверть
        } else if (x < 0 && y > 0) {
            count_quarter[1]++; //друга чверть
        } else if (x < 0 && y < 0) {
            count_quarter[2]++; //третя чверть
        } else if (x > 0 && y < 0) {
            count_quarter[3]++; //четверта чверть
        }
    }

    int max_quarter = 0;  // знайдення чверті з найбільшою кількістю точок, використано цілочисельні змінні
    for (int i = 1; i < 4; ++i) { // використано цикл for для знаходження найбільшої чверті
        if (count_quarter[i] > count_quarter[max_quarter]) { //використано умовний оператор if для порівняння к-ті точок в чвертях
            max_quarter = i; // оновлення індексу чверті з найбільшою кількістю точок
        }
    }

    cout << "В чверті " << max_quarter + 1 << " більше всього точок.\n"; // виведення результату, використано оператор виведення

    return 0; // завершення головної ф-ції, повернення значення 0.
}
