#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout, std::setprecision, std::fixed;

/*
 *              1
 * y = ln(------------)
 *          2+2x+x^2
 */

double yByStdMethod(double x) {
    return log(1 / (2 + 2 * x + pow(x, 2)));
}

double yByPartialSum(double x, double n) {
    // first element -(x+1)^2
    double current = -pow(x + 1, 2);
    double prev, sum = current;

    for (int i = 1; i <= n; ++i) {
        prev = current;
        // recurrence relation
        current = prev * (-n * pow(x + 1, 2)) / (n + 1);
        sum += current;
    }

    return sum;
}

double yByEpsilon(double x, double epsilon = 0.0001) {
    // first element -(x+1)^2
    double current = -pow(x + 1, 2);
    double prev = 0, sum = current;

    double diff = fabs(current - prev);
    for (int n = 1; diff >= epsilon; ++n) {
        diff = fabs(current - prev);
        prev = current;

        // recurrence relation
        current = prev * (-(n * pow(x + 1, 2)) / (n + 1));
        sum += current;
    }

    return sum;
}

int main() {
    double  e = 1e-4,
            n = 40;

    double a = -2, b = -0.1, k = 10;

    cout << setprecision(10) << fixed;

    double x = a;
    while (x <= b) {
        cout << "X = "  << x                    << "\t"
             << "SN = " << yByPartialSum(x, n)  << "\t\t"
             << "SE = " << yByEpsilon(x, e)     << "\t\t"
             << "Y = "  << yByStdMethod(x)      << "\n";

        x += (b - a) / k;
    }
}
