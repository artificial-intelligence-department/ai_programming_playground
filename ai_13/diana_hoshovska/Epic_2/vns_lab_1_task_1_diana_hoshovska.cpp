#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a = 1000.0;
    double b = 0.0001;
    double c, d, e, f, g;

    c = pow(a - b, 3);
    d = pow(a, 3);
    e = pow(b, 2);
    f = pow(b, 3);
    g = pow(a, 2);

    double result1 = (c - d - 3*a*e)/(f - 3*g*b);
    cout << result1 << endl;

    return 0;
}
