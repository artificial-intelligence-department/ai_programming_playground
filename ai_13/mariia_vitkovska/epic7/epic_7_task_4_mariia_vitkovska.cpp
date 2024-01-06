#include <iostream>
#include <iomanip> 

using namespace std;

double calculateFunction(double x) {
    return 2 * x * x - 5 * x - 8;
}

int main() {
    double x_min = -4.0;
    double x_max = 4.0;
    double x_step = 0.5;

    cout << setw(10) << "x" << setw(15) << "y" << endl;

    for (double x = x_min; x <= x_max; x += x_step) {
        double y = calculateFunction(x);
        cout << setw(10) << fixed << setprecision(2) << x << setw(15) << y << endl;
    }

    return 0;
}
