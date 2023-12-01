#include <iostream>
#include <cmath>
using namespace std;


double square (double x1, double y1, double x2, double y2, double x3, double y3) {
    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double dx2 = x3 - x1;
    double dy2 = y3 - y1;

    double s = (dx1 * dx2 + dx2 * dy2) / 2;
    return sqrt(s * (s - dx1 * dx1) * (s - dy1 * dy1) * (s - dx2 * dx2) * (s - dy2 * dy2));
}

int main (){
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 3.0;
    double y2 = 4.0;
    double x3 = 5.0;
    double y3 = 6.0;

    double area = square(x1, y1, x2, y2, x3, y3);

    cout << "Area of triangle: " << area << endl;

    return 0;

}