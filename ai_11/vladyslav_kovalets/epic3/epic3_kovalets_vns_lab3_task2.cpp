#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    long double S = 0;
    const long double pi = 3.14159265358979323846;
    const long double e = 0.0001; 
    long double a = pi / 5, b = (9 * pi) / 5;
    int n = 4000, k = 10;
    long double r = (b - a) / k;

    // Визначення кількості значень після коми
    int precision = -log10(e);

    for (long double x = a; x <= b + r / 2; x += r) 
    {
        S = 0;
        for (int i = 1; i <= n; i++) 
        {
            long double term = cos(i * x) / i;
            if (abs(term) >= e) 
            {
                S += term;
            } else 
            {
                break;
            }
        }

        // Виведення з використанням точності е
        cout.precision(precision);
        cout << "S(" << x << ") = " << S << endl;
    }

    return 0;
}
