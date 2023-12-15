#include <iostream>
#include <math.h>;
using namespace std;
int main()
{

    double step = (1 - 0.1) / 10;
    for (double x = 0.1; x <= 1; x += step)
    {
        double y = 2 * (pow(cos(x), 2) - 1);
        cout << "X=" << x << "  ";

        double sum1 = -pow(2 * x, 2) / 2;
        double add1 = -pow(2 * x, 2) / 2;
        double sum2 = -pow(2 * x, 2) / 2;
        double add2 = -pow(2 * x, 2) / 2;
        for (int n = 1; n < 15; n++)
        {
            add1 = add1 * (-1) * pow(2 * x, 2) / ((2 * n + 2) * (2 * n + 1));
            sum1 = sum1 + add1;
        }
        cout << "SN=" << sum1 << " ";
        for (int n = 1; fabs(add2) >= 0.0001; n++)
        {
            add2 = add2 * (-1) * pow(2 * x, 2) / ((2 * n + 2) * (2 * n + 1));
            sum2 = sum2 + add2;
        }
        cout << "SE=" << sum2 << " ";
        cout << "Y=" << y;
        cout << endl;
    }
   
}
