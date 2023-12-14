#include <iostream>

using namespace std;

int main() {

// Введення значень сторін трикутника.
    double a, b, c; // Сторони трикутника, створюємо змінні типу double
    cout << "Side a: ";
    cin >> a;
    cout << "Side b: ";
    cin >> b;
    cout << "Side c: ";
    cin >> c;

    double p = (a + b + c) / 2; // Формула півпериметра трикутника, створюємо змінну типу double

    // Використано оператор double та вводимо формулу обчислення висоти трикутника
    double ha = 2/a * sqrt(p * (p - a) * (p - b) * (p - c));
    double hb = 2/b * sqrt(p * (p - a) * (p - b) * (p - c));
    double hc = 2/c * sqrt(p * (p - a) * (p - b) * (p - c));

    // Виводимо значення висот трикутника
    cout << "Height a = " << ha << endl;
    cout << "Height b = " << hb << endl;
    cout << "Height c = " << hc << endl;

    return 0;
}