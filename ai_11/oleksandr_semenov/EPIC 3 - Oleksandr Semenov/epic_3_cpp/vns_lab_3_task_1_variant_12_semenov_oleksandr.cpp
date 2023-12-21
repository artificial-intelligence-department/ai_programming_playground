#include <iostream>
#include <cmath>

using namespace std;

double exactFunction(double x) {
    return cos(x) * cos(x) * cos(x) + cos(x) * sin(x) * sin(x) * sin(x);
}

double powerSeriesExpansion(int n, double x) {
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        sum += term;
    }
    return sum;
}

double computeFunctionWithPrecision(double x, double epsilon) {
    double sum = 0.0;
    int i = 0;
    double term = 1.0;

    while (fabs(term) > epsilon) {
        term = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        sum += term;
        i++;
    }

    return sum;
}

int main() {
    const int n = 35; // заданий n
    const double a = 0.0;
    const double b = 0.8;
    const int k = 10;
    const double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << "Обчислення функції" << endl;
    cout << "X\tSN\tSE\tY" << endl;

    for (double x = a; x <= b; x += step) {
        double exactValue = exactFunction(x);
        double approxValueN = powerSeriesExpansion(n, x);
        double approxValueEpsilon = computeFunctionWithPrecision(x, epsilon);

        cout << x << "\t" << approxValueN << "\t" << approxValueEpsilon << "\t" << exactValue << endl;
    }

    return 0;
}
