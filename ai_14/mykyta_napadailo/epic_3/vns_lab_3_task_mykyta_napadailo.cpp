#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    const float pi = 3.1415, a = 0.1, b = 0.8, eps = 0.0001;
    for (float x = a; x <= b; x+=(b-a)/10)
    {
        long double Sn = 0, Se = 0, e = 1;
        for (int n = 1; n <= 50; n++)
        {
            Sn += cos(2*n*x)/(4*n*n - 1);
        }
        for (int n = 1; abs(e) > eps; n++)
        {
            e = cos(2*n*x)/(4*n*n - 1);
            Se += e;
        }
        long double y = 0.5 - (pi/4 * abs(sin(x)));

        cout << "X=" << x << "    Sn=" << Sn << "   Se=" << Se << "   Y=" << y << endl;
    }

return 0;
}