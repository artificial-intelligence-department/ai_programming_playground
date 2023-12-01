#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    const double a = M_PI / 5.0;
    const double b = M_PI;
    const int k = 10;
    const int n = 40;
    const double eps = 0.0001;
    double krok = (b - a) / k;
    double x = M_PI / 5.0;

    do
    {

        double SN = 0;
        double SE = 0;
        double se = 1;
        float eps = 0.0001;
        for (int i = 1; i <= n; i++)
        {
            double sn = (cos((2 * i - 1) * x)) / pow((2 * i - 1), 2);
            SN = SN + sn;
        }

        int i;
        for (i = 1; abs(se) >= eps; i++)
        {
            se = (cos((2 * i - 1) * x)) / pow((2 * i - 1), 2);
            SE += se;
        }

        double y = (pow(M_PI, 2)) / 8 - (M_PI / 4) * abs(x);

        cout << "X=" << x << " "
             << "SN=" << SN << " "
             << "SE=" << SE << " "
             << "Y=" << y << " \n";

        x += krok;
    } while (x <= M_PI);

    return 0;
}