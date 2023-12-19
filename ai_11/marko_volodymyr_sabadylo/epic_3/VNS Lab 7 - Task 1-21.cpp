#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

//обчислення кутів трикутника за його сторонами
double triangleAngle(double a, double b, double c) {
    double angleRad = acos((a * a + b * b - c * c) / (2 * a * b));
    return angleRad * 180 / M_PI; // Перетворення радіан в градуси
}

//обчислення кутів n-кутника за заданими сторонами
double angles(int sides, ...) {
    va_list args;
    va_start(args, sides);

    double sumOfAngles = 0.0;
    for (int i = 0; i < sides - 2; ++i) {
        double side = va_arg(args, double);
        double nextSide = va_arg(args, double);
        double thirdSide = va_arg(args, double);

        sumOfAngles += triangleAngle(side, nextSide, thirdSide);
    }

    va_end(args);

    return sumOfAngles;
}

int main() {
    // Знаходження кутів трикутника
    double angleTriangle = angles(3, 3.0, 4.0, 5.0);
    cout << angleTriangle << endl;

    // Знаходження кутів 9-кутника
    double anglePolygon9 = angles(9, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    cout << anglePolygon9 << endl;

    // Знаходження кутів 11-кутника
    double anglePolygon11 = angles(11, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
    cout <<  anglePolygon11 <<  endl;

    return 0;
}