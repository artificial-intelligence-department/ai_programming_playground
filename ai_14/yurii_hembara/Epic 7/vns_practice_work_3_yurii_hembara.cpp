#include<iostream>
#include<cmath>
using namespace std;

// Функція для обчислення площі трикутника за координатами його кутів
float calculateTriangleArea(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return area;
}

int main() {
    // Оголошення змінних
    int total_Minutes, hours, minutes;

    // Введення часового інтервалу в хвилинах
    cout << "Введіть часовий інтервал (в хвилинах) > ";
    cin >> total_Minutes;

    // Розрахунок годин і залишкових хвилин
    hours = total_Minutes / 60;
    minutes = total_Minutes % 60;

    // Виведення результату
    cout << total_Minutes << " хвилин - це " << hours << " г. " << minutes << " хв." << endl;

    // Задача №2
    // Оголошення змінних для координат кутів трикутника
    float x1, y1, x2, y2, x3, y3;

    // Введення координат кутів трикутника від користувача
    cout << "Введіть координати першого кута (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Введіть координати другого кута (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Введіть координати третього кута (x3 y3): ";
    cin >> x3 >> y3;

    // Обчислення та виведення площі трикутника
    float area = calculateTriangleArea(x1, y1, x2, y2, x3, y3);
    cout << "Площа трикутника: " << area << endl;

    return 0;
}
