#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    const double PI = 3.141592653589793;
    double a = 0.1, b = 1.0;
    int k = 10, n = 25;
    double eps = 0.0001;

    for (double x = a; x <= b; x += (b - a) / k) {
        double sn = 0.0, se = 0.0, y;

        y = exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));

        for (int i = 0; i <= n; ++i) {
            sn += (cos(i * PI / 4) / factorial(i)) * pow(x, i);
        }
       
        double t=x;
        int i = 1;
        while (t > eps) {
            se += t;
            t *= ((x * x) / ((2 * i) * (2 * i + 1)));
            ++i;
        }

        cout << "X = " << x << "  "<< " SN = " << sn<< "  " << " SE = " << se<< "  " << " Y = " << y << endl;
    }

    return 0;
}
