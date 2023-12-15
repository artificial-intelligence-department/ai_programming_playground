#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a;
    double b;

    cout << ("Введіть a i b з значенням double\n");
    cin >> a >> b;

    double c = pow(a + b, 3);
    double d = pow(a, 3);
    double e = 3 * a * pow(b, 2) + pow(b, 3)+ 3 * pow(a, 2)*b;
    double g = c - d;
    double z = g / e;

    cout << (z) << endl;

    float a1;
    float b1;

    cout << ("Введіть a i b з значенням float \n");
    cin >> a1 >> b1;

    float c1 = pow(a1 + b1, 3);
    float d1 = pow(a1, 3);
    float e1 = 3 * a1 * pow(b1, 2) + pow(b1, 3)+ 3 * pow(a1, 2)*b1;
    float g1 = c1 - d1;
    float z1 = g1 / e1;

    cout << (z1) << endl;


    return 0;
}