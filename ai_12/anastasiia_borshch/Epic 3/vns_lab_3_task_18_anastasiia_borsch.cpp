#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 0.5 - 3.14 / 4 * abs(sin(x));
}

double df(double x) {
    return -3.14 / 4 * cos(x);
}

double newton_raphson(double x, double eps) {
    double delta = f(x) / df(x);
    while (abs(delta) >= eps) {
        delta = f(x) / df(x);
        x -= delta;
    }
    return x;
}

int main() {
    double a = 0.1, b = 0.8, k = 10;
    double h = (b - a) / k;
    double x = a;
    double exact, sn, se;
    int n = 50;
    double eps = 0.0001;

    cout << "x\t\tf(x) exact\tf(x) sn\tf(x) se\n";
    for (int i = 0; i <= k; i++) {
        exact = 0.5 - 3.14 / 4 * abs(sin(x));
        sn = 0;
        se = 0;
        for (int j = 0; j <= n; j++) {
            sn += pow(-1, j) * pow(x, 2 * j + 1) / (2 * j + 1);
        }
        double term = x;
        int j = 1;
        while (abs(term) >= eps) {
            se += term;
            term *= -1 * x * x / ((2 * j) * (2 * j + 1));
            j++;
        }
        se += term;

        cout << x << "\t" << exact << "\t" << sn << "\t" << se << "\n";
        x += h;
    }

    return 0;
}

