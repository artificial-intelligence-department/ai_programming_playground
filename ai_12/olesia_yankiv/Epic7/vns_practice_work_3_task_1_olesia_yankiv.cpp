//vns 3 task 1 variant 7

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Оголошення змінних для довжин сторін, кута та площі трикутника
    double side1, side2, angleInGrad, area;

    // Ввід довжин сторін трикутника в сантиметрах
    cout << "Enter the sides length of triangle (in sm): " << endl;
    cin >> side1;
    cin >> side2;

    // Ввід значення кута в градусах
    cout << "Enter the value of angle (in grad): " << endl;
    cin >> angleInGrad;

    // Переведення кута в радіани
    double angleInRad = angleInGrad * M_PI / 180.0;

    // Розрахунок синуса кута
    double sinusValue = sin(angleInRad);

    // Розрахунок площі трикутника за формулою
    area = ((side1 * side2) * sinusValue) / 2;

    // Перевірка на від'ємність площі та виведення повідомлення про помилку
    if (area < 0)
        cout << "\nERROR!" << endl;

    // Виведення значення площі трикутника
    cout << "The area values " << area << "(sm^2)" << endl;

    return 0;
}
