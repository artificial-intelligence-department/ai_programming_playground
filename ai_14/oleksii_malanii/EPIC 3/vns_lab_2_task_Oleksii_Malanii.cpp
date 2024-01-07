#include <iostream>
#include <cmath>
using namespace std;
int main () {
    double a = 1;
    double sum = 0.0;
    double epsilon = 0.0001;
    for (int n = 2; fabs(a) > epsilon; ++n) {
        sum += a;
        a = pow(-1, n - 1) / pow(n, n);
    }
    cout << sum;
    return 0;
}