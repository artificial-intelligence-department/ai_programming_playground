// 25
#include <iostream>
#include <cmath>
using namespace std;

double calc_a(double x, double y)
{
    return y +
           x /
           (pow(y, 3) + abs(pow(x, 2) / (y + pow(x * x, 1 / 3))));
}

double calc_b(double x)
{
    return 1 + pow(tan(x / 2), 2);
}

int main()
{
    const double x = 1.23, y = 0.79;

    cout << "A: " << calc_a(x, y) << "\n"
         << "B: " << calc_b(x) << "\n";
    return 0;
}
