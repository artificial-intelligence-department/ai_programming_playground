#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double radius, height;

    cout << "Обчислення площі поверхні циліндра." << endl;
    cout << "Введіть радіус підстави (см): ";
    cin >> radius;

    if (radius <= 0) {
        cerr << "Помилка: Радіус повинен бути більше за 0." << endl;
        return 1; 
    }

    cout << "Введіть висоту циліндра (см): ";
    cin >> height;

    if (height <= 0) {
        cerr << "Помилка: Висота повинна бути більше за 0." << endl;
        return 1;
    }

    double surfaceArea = 2 * M_PI * radius * (radius + height);

    cout << "Площа поверхні циліндра: " << surfaceArea << " кв.см." << endl;

    return 0;
}
