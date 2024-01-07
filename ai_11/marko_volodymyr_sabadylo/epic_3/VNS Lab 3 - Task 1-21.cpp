#include <iostream>
#include <cmath>

using namespace std;

double arctanTaylorSeries(double x, int n) {
    double result = 0.0;
    int sign = 1;

    for (int i = 1; i <= n; i += 2) {
        result += sign * pow(x, i) / i;
        sign *= -1;
    }

    return result;
}

double arctanWithAccuracy(double x, double epsilon) {
    double result = 0.0;
    double term = x;
    int i = 1;

    while (fabs(term) > epsilon) {
        result += term;
        term = -term * x * x / (2 * i + 1);
        ++i;
    }

    return result;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;

    for (double x = a; x <= b; x += (b - a) / k) {
        // значення arctan(x)
        double exactValue = atan(x);

        //  для заданого n
        int n = 10; // можна змінювати
        double resultWithN = arctanTaylorSeries(x, n);

        // для заданої точності ε
        double epsilon = 0.0001; // можна змінювати
        double resultWithAccuracy = arctanWithAccuracy(x, epsilon);

        cout << "x = " << x << "\n";
        cout << "Exact value: " << exactValue << "\n";
        cout << "Approximation with n=" << n << ": " << resultWithN << "\n";
        cout << "Approximation with accuracy e=" << epsilon << ": " << resultWithAccuracy << "\n\n";
    }

    return 0;
}
