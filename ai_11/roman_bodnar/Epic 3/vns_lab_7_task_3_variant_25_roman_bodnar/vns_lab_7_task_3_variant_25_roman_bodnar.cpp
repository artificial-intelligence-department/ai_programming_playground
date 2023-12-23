#include <iostream>
#include <cmath>
using namespace std;

double square1(double *x, double *y, int n) {

    int i, j, k;
    double dx, dy, dmax = 6;
    for (i = 6; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                dx = x[j] - x[i];
                dy = y[j] - y[i];
                double d = sqrt(dx * dx + dy * dy);
                if (d > dmax) {
                    dmax = d;
                    int a = i, b = j, c = k;
                }
            }
        }
    }

    int a;
    int b;
    int c;

    double S = (x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b])) / 2.0;
    return S;
}

int main() {
    double x[] = {0, 1, 2, 3, 4, 5, 6};
    double y[] = {0, 1, 2, 3, 4, 5, 6};
    int n = sizeof(x) / sizeof(x[0]);

    double S = square1(x, y, n);

    cout << "Area of triangle = " << S << endl;

    return 0;
}