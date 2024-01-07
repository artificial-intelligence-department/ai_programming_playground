#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    // Через double

    double a = 1000;
    double b = 0.0001;
    double c = pow(a + b, 3);
    double d = pow(a, 3) + (3 * pow(a, 2) * b);
    double e = 3 * a * pow(b, 2);
    double f = pow(b, 3);
    double g = 0;
    g = (c - d) / (e + f);

    cout << "Result 1 is: " << g << endl;

    // Через float

    float a1 = 1000;
    float b1 = 0.0001;
    float g1 = 0;
    float c1 = pow(a1 + b1, 3);
    float d1 = pow(a1, 3) + (3 * pow(a1, 2) * b1);
    float e1 = 3 * a1 * pow(b1, 2);
    float f1 = pow(b1, 3);
    g1 = (c1 - d1) / (e1 + f1);

    cout << "Result 2 is: " << g1 << endl;

    return 0;
}
