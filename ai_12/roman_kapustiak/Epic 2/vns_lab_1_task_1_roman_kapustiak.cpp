#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a = 1000, b = 0.0001;

    double value1 = pow(a + b, 3);
    double value2 = pow(a, 3);

    double numerator = value1 - value2;

    double value3 = pow(b, 2);
    double value4 = pow(b, 3);
    double value5 = pow(a, 2);

    double denominator = 3 * a * value3 + value4 + 3 * value5 * b;

    double result = numerator / denominator;

    cout << result;

    return 0;
}
