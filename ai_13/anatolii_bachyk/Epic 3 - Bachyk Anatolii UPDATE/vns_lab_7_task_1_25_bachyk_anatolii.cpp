#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double length(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = length(x1, y1, x2, y2);
    double b = length(x2, y2, x3, y3);
    double c = length(x3, y3, x1, y1);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double square1(vector<Point> points) {
    int n = points.size();
    double max_square = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                double s = square(points[i].x, points[i].y, points[j].x, points[j].y, points[k].x, points[k].y);
                max_square = max(max_square, s);
            }
        }
    }

    return max_square;
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2, y2: ";
    cin >> x2 >> y2;
    cout << "Enter x3, y3: ";
    cin >> x3 >> y3;

    double result = square(x1, y1, x2, y2, x3, y3);
    cout << "The area of the triangle is: " << result << endl;

    vector<Point> points = {{x1, y1}, {x2, y2}, {x3, y3}};
    double result1 = square1(points);
    cout << "The area of the largest triangle is: " << result1 << endl;

    return 0;
}


