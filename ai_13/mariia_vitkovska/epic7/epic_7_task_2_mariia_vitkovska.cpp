#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateZ(double x, double b) {
    return sqrt(4 * b + x * x) / 2;
}

double calculateY(double x, double b) {
    double z = calculateZ(x, b);
    return exp(x / 2) * pow(b, x) * (cos(z) + sin(z));
}

int main() {
    double x_min = 1.0, x_max = 2.0, x_step = 0.2;
    double b_min = 2.0, b_max = 8.0, b_step = 2.0;

    cout << setw(10) << "x" << setw(10) << "b" << setw(15) << "y" << endl;

    for (double x = x_min; x <= x_max; x += x_step) {
        for (double b = b_min; b <= b_max; b += b_step) {
            double y = calculateY(x, b);
            cout << setw(10) << fixed << setprecision(2) << x
                 << setw(10) << fixed << setprecision(2) << b
                 << setw(15) << fixed << setprecision(4) << y << endl;
        }
    }

    return 0;
}
