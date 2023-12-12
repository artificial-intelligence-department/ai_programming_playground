#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Ініціалізація змінних
    float x = 1.25, y = 0.93;
    float a = 0, b = 0, p, temp1, temp2;

    // Обчислення значення a
    temp1 = pow((x + y), 2) / pow((x + 4), 3);
    temp2 = -1 * pow(M_E, (-1 * x + 2)) + pow(x, 3) + 4;
    a = (1 - y) * temp1 / temp2;

    // Виведення значення a
    cout << "a = " << a << endl;

    // Обчислення значення b
    temp1 = 1 + cos(y - 2);
    temp2 = pow(x, 2) + pow(sin(y - 2), 2);
    b = temp1 / temp2;

    // Виведення значення b
    cout << "b = " << b << endl;

    // Обчислення та виведення значення p
    p = a / b;
    cout << "p = " << p << endl;

    return 0;
}
