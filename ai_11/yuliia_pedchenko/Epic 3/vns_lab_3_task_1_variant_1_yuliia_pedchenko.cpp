// y=3^x      0,1<=x<=1
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int f)
{
    if (f == 0 || f == 1) return 1;
    return f * factorial(f - 1);
}

const double e = 0.0001;

int main()
{
    for (float x = 0.1; x <= 1; x += 0.09)
    {
        cout << "X=" << x << "\t";
        double Y = pow(3, x);
        double SN = 0, SE = 0;

        for (int p = 0; p <= 10; p++) {
            SN = SN + pow(log(3), p) / factorial(p) * pow(x, p);
        }

        double an = 1;
        for (int p = 0; abs(an)>= e; p++) {
            an = pow(log(3), p) / factorial(p) * pow(x, p);
            SE += an;
            // SE = SE + pow(log(3), p) / factorial(p) * pow(x, p);
        }
        


        cout << "SN=" << SN << "\t"
             << "SE=" << SE << "\t"
             << "Y=" << Y << "\n";
    }
}