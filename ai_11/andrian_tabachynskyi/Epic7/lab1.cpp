#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x = 1.2;
    double y = -1.22;
    double z = 3.5;
    double a, b;
    const double pi = 3.14159265;
    b = 1 + (pow(z, 2) / (3 + pow(z, 2) / 5));
    a = 2 * cos(x - pi / 6) * b / (0.5 + pow(sin(y), 2));
    cout << a << endl;
    cout << b << endl;
    cout << cos(pi);
    return 0;
}