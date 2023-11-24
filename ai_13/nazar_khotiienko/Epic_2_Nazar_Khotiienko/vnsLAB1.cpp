#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a;
    double b;

    cout << ("Введіть a i b з значенням double\n");
    cin >> a >> b;

    double c = pow(a, 3) + pow(b, 3);
    double d = pow(a, 3);
    double e = 3 * a * pow(b, 2) + 3 * a * pow(b, 3);
    double g = c - d;
    double z = g / e;

    cout << (z) << endl;

    float a1;
    float b1;

    cout << ("Введіть a i b з значенням float \n");
    cin >> a1 >> b1;

    double c1 = pow(a1, 3) + pow(b1, 3);
    double d1 = pow(a1, 3);
    double e1 = 3 * a1 * pow(b1, 2) + 3 * a * pow(b1, 3);
    double g1 = c1 - d1;
    double z1 = g1 / e1;

    cout << (z1) << endl;


    return 0;
}