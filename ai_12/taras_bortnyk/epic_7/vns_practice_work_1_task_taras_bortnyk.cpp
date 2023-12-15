#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double pi = 3.14159;
    double R = 5.0; // Радіус основи більшого конуса
    double r = 3.0; // Радіус основи меншого конуса
    double h = 7.0; // Висота конуса

    // Обчислення довжини бічної поверхні (l)
    double l = sqrt(pow(h, 2) + pow(R - r, 2));

    // Обчислення площі поверхні зрізаного конуса (S)
    double S = pi * (R + r) * l + pi * pow(R, 2) + pi * pow(r, 2);

    // Обчислення об'єму зрізаного конуса (V)
    double V = pi / 3 * (pow(R, 2) + pow(r, 2) + R * r) * h;

    // Виведення результатів
    cout << "Surface area of a truncated cone: " << S << endl;
    cout << "Volume of a truncated cone: " << V << endl;

    return 0;
}
