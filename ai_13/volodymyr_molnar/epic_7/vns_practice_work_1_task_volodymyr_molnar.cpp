#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double P{};
    double b{ 15.5 }, x{ -2.9 }, a = 1.5;
    double temp_x = pow(x, 3);
    double y = (pow(cos(temp_x), 2)) - (x / pow((pow(a, 2) + pow(b, 2)), 1 / 2));
    double P1 = pow(pow(x, 2) + b, 1/2) - pow(b, 2) * pow(sin(x + a), 3) / x* y;
    cout << "P = " << P1 << "\ny = " << y;

    return 0;
}