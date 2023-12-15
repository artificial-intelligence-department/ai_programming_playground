#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double y(double );
double sn(double, int);
double se(double , double);

int main() {
    cout << fixed << setprecision(9);
    double a {0.2};
    double b {1};
    int k {10};
    double step = (b - a) / k;
    int n {10};
    double epsilon {0.0001};

    for (double x = a; x <= b; x += step) {
        cout << "X: " << x << " ";
        cout << "SN: " << sn(x, n) << " ";
        cout << "SE: " << se(x, epsilon) << " ";
        cout << " Y: " << y(x) << endl;
    }

    return 0;
}

double y(double x) {
    return 0.5 * log(x);
}

double sn(double x, int n) {
    double suma {0};
    double value {1};
    for (int i = 1; i <= n; ++i) {
        value *= (pow((x - 1) / (x + 1),2*i+1));
        suma += value / (2 * i + 1);
    }
    return suma;
}

double se(double x, double epsilon) {
    double suma {0};
    double value {1};
    int i = 1;

    while (value > epsilon) {
        value *= pow((x - 1) / (x + 1),2*i+1);
        suma += value / (2 * i + 1);

        i++;
    }
    return suma;
}
