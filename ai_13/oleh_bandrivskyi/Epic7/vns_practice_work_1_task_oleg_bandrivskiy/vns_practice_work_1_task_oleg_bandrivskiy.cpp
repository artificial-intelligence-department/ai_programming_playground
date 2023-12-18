#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.3;
    double b = 0.9;
    double x = 0.53;

    double Y = pow(a, 2) * x + (pow(b, -x) * cos(a + b) * x) / fabs(x + 1);

    double R = (sqrt(pow(x, 2) + b) * pow(sin(x + a), 3)) / x;

    cout << "Y = " << Y << endl;
    cout << "R = " << R << endl;

    return 0;
}
