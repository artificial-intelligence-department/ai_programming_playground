#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    long double a = 0.5, b = 2.9, x = 0.3, A, B;
    A = (pow(a, x) + (pow(b, (-x)) * sin(a - b))) / sqrt(fabs(a - b));
    cout << "Значення числа A: " << A << endl;
    B = pow(a * M_E, (-sqrt(a))) * cos((b * x) / a);
    cout << "Значення числа B: " << B << endl;
    return 0;
}
