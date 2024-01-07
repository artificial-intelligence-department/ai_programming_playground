#include <iostream>
#include <cmath>
using namespace std;

double calculate_P(double x, double y)
{
    return (1 + pow(sin(x + 1), 2)) / (2 + abs((x - 2 * x*x*x) / (1 + x*x*y*y*y))) + x*x*x*x;
}
double calculate_Q(double z)
{
    return pow(cos(atan(1 / z)), 2);
}

int main()
{
    const double x = 0.25, y = 0.79, z = 0.81;
    double P = calculate_P(x, y);
    double Q = calculate_Q(z);

    cout << "For x = " << x << ", y = " << y << ", z = " << z << ":\n"
         << "P = " << P << "\nQ = " << Q << endl;
}