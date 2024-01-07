#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Оголошення та ініціалізація змінних
    float R = 2, r = 1, h = 3, l;
    float S, V;

    // Розрахунок довжини обхвату бічної поверхні
    l = pow((h * h + R - r), 0.5);

    // Розрахунок площі поверхні тіла
    S = M_PI * (R + r) * l + M_PI * R * R + M_PI + r + r;

    // Розрахунок об'єму тіла
    V = (M_PI / 3) * h * (R * R + r * r + R * r);

    // Виведення результатів
    cout << "S = " << S << endl;
    cout << "V = " << V << endl;

    return 0;
}
