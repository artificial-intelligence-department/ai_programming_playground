#include <iostream>
#include <cmath>
#include <initializer_list>

struct Point {
    double x, y, z;
};

double distance(const Point &p1, const Point &p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

double area_triangle (const Point &p1, const Point &p2, const Point &p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area_poligon (const std::initializer_list<Point> &vertices) {
    double area = 0.0;
    auto it = vertices.begin();
    Point p1 = *it;
    Point p2 = *(++it);

    while (++it != vertices.end()) {
        Point p3 = *it;
        double a = distance(p1, p2);
        double b = distance(p2, p3);
        double c = distance(p3, p1);
        double s = (a + b + c) / 2.0;
        double triangleArea = sqrt(s * (s - a) * (s - b) * (s - c));
        area += triangleArea;

        p2 = p3;
    }
    return area;
}
 using namespace std;

int main() {
    Point p1, p2, p3;

    cout << "Input x, y, z for point P1: ";
    cin >> p1.x >> p1.y >> p1.z;
    cout << "Input x, y, z for point P2: ";
    cin >> p2.x >> p2.y >> p2.z;
    cout << "Input x, y, z for point P3: ";
    cin >> p3.x >> p3.y >> p3.z;

    cout << "Довжина сторони AB: " << distance(p1, p2) << endl;
    cout << "Довжина сторони BC: " << distance(p2, p3) << endl;
    cout << "Довжина сторони CA: " << distance(p3, p1) << endl;

    cout << "Площа трикутника ABC: " << area_triangle (p1, p2, p3) << endl;

    initializer_list<Point> polygonVertices = {p1, p2, p3};
    cout << "Площа опуклого багатокутника ABC: " << area_poligon (polygonVertices) << endl;

    return 0;
}
