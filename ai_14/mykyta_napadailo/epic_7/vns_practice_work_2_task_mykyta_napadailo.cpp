#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double a = 0.3, b = 5, h = 0.1;
    int count = 0;
    for (double x = a; x <= b; x += h)
    {
        double y = cos(x*x) * exp(-x);
        if (y < 0) count++;
    }

    cout << "On interval [" << a << ";" << b << "] function is negative " << count << " times\n";
}