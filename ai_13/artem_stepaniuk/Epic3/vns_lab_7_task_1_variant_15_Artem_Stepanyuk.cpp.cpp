#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return (1 + pow(x, 2)) / (2 * atan(x));
}

int main() {
    const int k = 10;
    const double a = 0.1;
    const double b = 1.0;
    const double epsilon = 0.0001;

    for (double x = a; x <= b; x += (b - a) / k) {
        double sn = 0.0;
        double se = 0.0;
        double y_exact = function(x);

        int n = 10;
        for (int i = 0; i <= n; ++i) {
            double an = pow(x, 2 * i + 1) / (2 * i + 1);
            sn += an;
        }

        double current_term = x;
        int i = 0;
        while (abs(current_term) >= epsilon) {
            se += current_term;
            ++i;
            current_term = -current_term * x * x * (2 * i - 1) / (2 * i + 1);
        }

        cout << "X=" << x << " SN=" << sn << " SE=" << se << " Y=" << y_exact << endl;
    }

    return 0;
}