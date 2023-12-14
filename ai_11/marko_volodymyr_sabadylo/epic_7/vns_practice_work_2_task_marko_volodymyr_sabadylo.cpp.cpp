#include <iostream>
#include <cmath>

using namespace std;

double calculate_ha(double a, double b, double c) {
    // Обчислення половини периметра
    double p = (a + b + c) / 2;

    // Обчислення висоти ha за заданою формулою
    double ha = (2 / a) * sqrt(p * (p - a) * (p - c));

    return ha;
}

int main() {
    // Введення п'яти наборів сторін трикутника
    for (int i = 0; i < 5; ++i) {
        double a, b, c;
        cout << "Enter the length of side a for triangle " << i + 1 << ": ";
        cin >> a;

        cout << "Enter the length of side b for triangle " << i + 1 << ": ";
        cin >> b;

        cout << "Enter the length of side c for triangle " << i + 1 << ": ";
        cin >> c;

        // Обчислення висоти для поточного трикутника
        double ha = calculate_ha(a, b, c);

        // Вивід результату
        cout << "For triangle " << i + 1 << ": height ha = " << ha << endl;
    }

    return 0;
}