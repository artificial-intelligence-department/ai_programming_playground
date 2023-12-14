#include <iostream>
#include <cmath>
using namespace std;
double Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "x1, y1 > ";
    cin >> x1 >> y1;
    cout << "x2, y2 > ";
    cin >> x2 >> y2;
    cout << "x3, y3 > ";
    cin >> x3 >> y3;
    double trianglearea = Triangle(x1, y1, x2, y2, x3, y3);
    cout << "Triangle Area: " << trianglearea << " sq.cm." << endl;
    return 0;
}
