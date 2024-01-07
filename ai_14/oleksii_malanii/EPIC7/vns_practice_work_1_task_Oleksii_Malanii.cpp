#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x = 1.45;
    double y = -1.22;
    double z = 3.5;
    double b = 1 + pow(z, 2) / (3 + pow(z, 2) / 5);
    double a = (2 * cos(x - M_PI / 6) * b) / (1.0 / 2 + pow(sin(y), 2));
    cout << "Result a: " << a << endl;
    cout << "Result b: " << b << endl;
    return 0;
}
