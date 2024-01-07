#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double length, width, height;

    cout << "Обчислення площі поверхні паралелепіпеда." << endl;
    cout << "Введіть початкові дані:" << endl;

    cout << "Довжина (см) > ";
    cin >> length;

    cout << "Ширина (см) > ";
    cin >> width;

    cout << "Висота (см) > ";
    cin >> height;

    double surfaceArea = 2 * (length * width + length * height + width * height);

    cout << "Площа поверхні: " << fixed << setprecision(2) << surfaceArea << " кв.см." << endl;

    const int metersInVersta = 1066; //Вимога №4: в коді використана як мінімум одна цілочисельна константа
    double distanceInKilometers, distanceInVersti;

    cout << "Введіть відстань у кілометрах для перерахунку у верстах: ";
    cin >> distanceInKilometers;

    distanceInVersti = distanceInKilometers * 1000 / 1066.8;

    cout << "Відстань у верстах: " << distanceInVersti << " верст." << endl;

    return 0;
}
