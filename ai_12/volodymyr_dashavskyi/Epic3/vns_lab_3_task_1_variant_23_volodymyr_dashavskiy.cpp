#include <iostream>
#include <cmath>
using namespace std;

double b = 1.0;
double a = 0.1;
int k = 10;
double step = (b - a) / k;
const double epsilon = 0.0001;
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    for (double c = a; c <= b; c = c + step)
    {
        double sn = 0.0;
        double se = 0.0;
        double y = 2 * (pow(cos(c), 2) - 1);
        // Обчислення sn:
        for (int n = 1; n <= 15; n++)
        {
            double an = pow(-1, n) * ((pow(2 * c, 2 * n)) / (2 * n) / factorial(2 * n));
            sn = sn + an;
        }
        // Обчислення se:
        int n = 1;
        double en = pow((-1), n) * ((pow(2 * c, 2 * n)) / (2 * n) / factorial(2 * n));

        while (fabs(en) >= epsilon)
        {

            se = se + en;
            n++;
            en = pow((-1), n) * ((pow(2 * c, 2 * n)) / (2 * n) / factorial(2 * n));
        }
        cout << " X = " << c << "; sn = " << sn << "; se = " << se << "; y = " << y << endl;
    }
    return 0;
}