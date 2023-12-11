#include <iostream>
#include <cmath>

using namespace std;

double calculateY(double x, double y, double a) {
    if ((pow(x, 2) + pow(y, 2)) <= pow(a, 2)) {
        return x / (15 * pow(x, 2));
    } else {
        return pow(x, 2) + exp(x);
    }
}

int main() {
    double a = 5.3;
    double y = 1.1;
    double h = 0.5;

    for (double x = -3; x <= 3; x += 0.5) {
        double result = calculateY(x, y, a);
        cout << "x = " << x << ", Y = " << result << endl;
    }

    return 0;
}