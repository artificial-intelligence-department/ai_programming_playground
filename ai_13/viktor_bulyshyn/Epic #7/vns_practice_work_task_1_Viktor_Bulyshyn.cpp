#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 1.1;
    double b = 0.004;
    double x = 0.2;

    double y = pow(sin(pow(a, 2)), 3) - cbrt(x/b);
//   z=x^2/a+cos^2(x+b)^3
    double z = (pow(x, 2)/a) + pow(cos(pow(x+b,3)),2);

    cout << y << endl;
    cout << z << endl;

    return 0;
}
