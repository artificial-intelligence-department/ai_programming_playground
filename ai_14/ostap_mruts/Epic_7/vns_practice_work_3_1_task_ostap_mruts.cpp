#include <iostream>
#include <cmath>

using namespace std;

double calculateTriangleArea(double side1, double side2, double angle) {
    double angleInRadians = (angle * M_PI) / 180.0;

    double area = 0.5 * side1 * side2 * sin(angleInRadians);
    return area;
}

int main() {
    double side1, side2, angle;

    cout << "Обчислення площі трикутника." << endl;
    cout << "Введіть довжини двох сторін (см) трикутника: ";
    cin >> side1 >> side2;
    cout << "Введіть величину кута між сторонами трикутника: ";
    cin >> angle;

    double triangleArea = calculateTriangleArea(side1, side2, angle);

    cout << "Площа трикутника: " << triangleArea << " кв.см." << endl;

    return 0;
}