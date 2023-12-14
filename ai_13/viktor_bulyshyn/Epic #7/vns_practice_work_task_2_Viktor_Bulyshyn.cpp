#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double hx = 0.5;
    double ha = 1.0;
    double a_min = 2.0;
    double a_max = 10.0;
    double x_min = 1.0;
    double x_max = 8.0;

    for (double a = a_min; a <= a_max; a += ha) {
        for (double x = x_min; x <= x_max; x += hx) {
            // Умова: a > x
            if (a > x) {
                double y = pow(a,2) + x;
                cout << "For a=" << a << ", x=" << x << ", y=" << y << endl;
            }
            // Умова: a = x
            else if (a == x) {
                double y = pow(a,2);
                cout << "For a=" << a << ", x=" << x << ", y=" << y << endl;
            }
            // Умова: a < x
            else {
                double y = pow(a,2) - x;
                cout << "For a=" << a << ", x=" << x << ", y=" << y << endl;
            }
        }
    }

    return 0;
}
