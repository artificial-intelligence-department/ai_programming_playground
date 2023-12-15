#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double step = (9.0*M_PI/5.0 - M_PI/5.0)/10.0;
    for (double x = M_PI/5; x <= 9*M_PI/5; x += step) {
        double y = -log(fabs(2*sin(x/2)));
        cout << "X=" << x << " ";
        double sum_a = 0.0;
        for (int i = 1; i <= 40; ++i) {
            sum_a += cos(i*x)/i;
        }
        cout << "SN=" << sum_a << " ";
        double sum_b = 0.0;
        double a_b = cos(x);
        for (int i = 2; fabs(a_b) >= 0.0001; ++i) {
            sum_b += a_b;
            a_b = cos(i*x)/i;
        }
        cout << "SE=" << sum_b << " ";
        cout << "Y=" << y << endl;
    }
    return 0;
}
