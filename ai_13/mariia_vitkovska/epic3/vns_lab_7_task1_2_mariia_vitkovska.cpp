#include <iostream>
#include <cmath>

using namespace std;

double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt(pow(x2-x1,2)+ pow(y2-y1, 2));
    double b = sqrt(pow(x3-x2,2)+ pow(y3-y2, 2));
    double c = sqrt(pow(x1-x3,2)+ pow(y1-y3, 2));

    // формула герона
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main() {
    // Введення координат вершин трикутника
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter the coordinates (x1, y1, x2, y2, x3, y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Обчислення площі трикутника
    double area = square(x1, y1, x2, y2, x3, y3);

    // Виведення результату
    cout << "the area of the triangle is: " << area << endl;

    return 0;
}