#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double minTimeToCatchMouse(double l, double d, double a, double b) {
    double time1 = 1e9, time2 = 1e9;
    if (0.5 * a > b) {
        time1 = d / (0.5 * a - b);
    }
    time2 = 2 * (0.5 * l / (a - b));
    return min(time1, time2);
}

int main() {
    double l, d, a, b;
    cin >> l >> d >> a >> b;
    cout << fixed << setprecision(7) << minTimeToCatchMouse(l, d, a, b) << endl;
    return 0;
}
