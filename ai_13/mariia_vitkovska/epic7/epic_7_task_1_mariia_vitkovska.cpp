#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double m =2.1, t = 1.02;
    int c = -1;
    double expression1 = m * tan(t) + fabs(c * sin(t));
    double P = cbrt(expression1);
    double K = cos(t) * cos(t) - m / cbrt(fabs(m * m - t * t));
    cout << "P= " << P << endl;
    cout << "K= " << K << endl;
    
    return 0;
}