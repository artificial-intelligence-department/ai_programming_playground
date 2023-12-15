#include <iostream>
#include <cmath>

using namespace std;

double SN(double x) {
    double sum = x;
    double term = x;

    for (int n = 1; n <= 20; ++n) {
        term *= -(x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
    }

    return sum;
}

double SE(double x) {
    double eps = 0.0001;
    double sum = x;
    double term = x;
    int n = 1;

    while (abs(term) > eps) {
        term *= -(x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
        ++n;
    }

    return sum;
}

double y(double x) {
    return (exp(x) - exp(-x)) / 2;
}

int main() {
    for (double x = 0.1; x <= 1.0; x += 0.1) {
        cout << "x = " << x;
        cout << " sn = " << SN(x);
        cout << " se = " << SE(x);
        cout << " y = " << y(x) << endl;
    }

    return 0;
}