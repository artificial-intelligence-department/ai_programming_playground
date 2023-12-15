#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double x, n, i;
double function_value (double x) {
    return log(1/(2 + 2 * x + pow(x, 2)));
    }


double function_with_n (double x, double n) {
    double first_term  = -pow(x + 1, 2), previous_term, sum;
    sum = first_term;
    double i;

        for (int i = 1; i <= n; ++i) {
            previous_term = first_term;
            first_term = (previous_term) * (-n * pow(x + 1, 2)) / (n + 1);
            sum += first_term;
            }

        return sum;
}

double function_with_E(double x, double E = 0.0001) {
    double first_term = -pow(x + 1, 2), previous_term = 0, sum = first_term;
    int n = 1;
    while (fabs(first_term - previous_term) > E) {
        previous_term = first_term; 

        first_term = previous_term * (-(n * pow(x + 1, 2)) / (n + 1));
        sum += first_term;
        ++n;
    }

        return sum;
}

int main() {
    double epsilon = 0.0001;
    int n = 40;
    double a = -2, b = -0.1;
    int k = 10;

    cout << setprecision(5) << fixed;

    cout << setw(10) << left << "X";
    cout << setw(10) << left << "SN";
    cout << setw(10) << left << "SE";
    cout << setw(10) << left << "Y" << endl;

    for (double x = a; x <= b; x += (b - a) / k) {
        cout << setw(10) << left << x;
        cout << setw(10) << left << function_with_n(x, n);
        cout << setw(10) << left << function_with_E(x, epsilon);
        cout << setw(10) << left << function_value(x) << endl;
    }

    return 0;
}

