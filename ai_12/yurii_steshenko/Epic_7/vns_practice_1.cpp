#include <iostream>
#include <cmath>
using namespace std;

constexpr double a = 0.7;
constexpr double b = 0.05;
constexpr double x = 0.5;

int main()
{
    const double R = (pow(x, 3) * (x + 1)) / pow(b, 2) - pow(sin(x * (x + a)), 2);
    const double S = sqrt((x * b) / a) + pow(cos(pow(x + b, 3)), 2);
    cout << R <<endl << S <<endl;
    return 0;
}