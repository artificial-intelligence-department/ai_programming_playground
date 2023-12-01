#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return (exp(x) - exp(-x)) / 2;
}


double S(double x, int n) {
    double sum = x;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, 2 * i + 1) / (2 * i + 1) * tgamma(2 * i);
    }
    return sum;
}


void calculate_for_n(double a, double b, int n) {
    double h = (b - a) / 10;
    for (double x = a; x <= b; x += h) {
        double S_n = S(x, n);
        double f_true = f(x);
        cout << "x = " << x << ", S_n = " << S_n << ", f_true = " << f_true << endl;
    }
}


void calculate_for_eps(double a, double b, double eps) {
    double h = (b - a) / 10;
    int n = 0;
    for (double x = a; x <= b; x += h) {
        double S_n = S(x, n);
        double S_n1 = S(x, n + 1);
        if (fabs(S_n1 - S_n) < eps) {
            cout << "x = " << x << ", S_n = " << S_n << ", f_true = " << f(x) << endl;
            break;
        }
        n++;
    }
}

int main() {
    double a = 0.1;
    double b = 1;


    calculate_for_n(a, b, 5);


    calculate_for_eps(a, b, 0.0001);

    return 0;
}
