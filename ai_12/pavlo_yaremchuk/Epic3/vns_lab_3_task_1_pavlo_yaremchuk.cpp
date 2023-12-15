#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double eps = 0.0001, y, a = 1.0, b = 2.0, sum = 0.0, ane, SE, SN;
    int k = 10, n;
    long long factorial;
    for (double x = a; x <= b + eps; x += (b - a)/k)
    {
        cout << "X=" << x;
        sum = 0;
        for (int n = 1; n <= 15; ++n)
        {
            factorial = 1;
            for (int i = 1; i <= n; ++i)
            {
                factorial *= i;
            }
            ane = ((pow (x, n))/factorial) * (x/(n + 1));
            sum += ane;
        }
        SN = 1 + x + sum;
        cout << " SN=" << SN;
        
        double ane1 = 1, sum1;
        sum1 = 0;
        for (int m = 1; ane1 > eps; ++m)
        {
            factorial = 1;
            for (int i = 1; i <= m; ++i)
            {
                factorial *= i;
            }
            ane1 = ((pow (x, m))/factorial) * (x/(m + 1));
            sum1 += ane1;
        }
        SE = 1 + x + sum1;
        cout << " SE=" << SE;
        y = exp(x);
        cout << " Y=" << y << endl;
    }
    return 0;
}