#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r; // Оголошення змінної для радіусу кулі

    cout << "Enter the radius of the sphere: ";
    cin >> r;

    // Обчислення об'єму кулі за формулою V = (4/3) * π * r^3
    double V = (3.0 / 4.0) * M_PI * pow(r, 3);

    // Обчислення площі поверхні кулі за формулою S = 4 * π * r^2
    double S = 4 * M_PI * pow(r, 2);

    // Вивід обчисленого об'єму кулі на екран
    cout << "Volume of the sphere: " << V << endl;

    // Вивід обчисленої площі поверхні кулі на екран
    cout << "Surface area of the sphere: " << S << endl;

    return 0;
}
