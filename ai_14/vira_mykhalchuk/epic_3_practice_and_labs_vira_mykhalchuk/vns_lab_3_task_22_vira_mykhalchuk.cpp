#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double e = 0.0001;
    const double a = 0.1;
    const double b = 1.0;
    const int n = 35;
    const int k = 10;

    for (int i = 0; i <= k; i++)
    {
        double x = a + i * ((b - a) / k);
        double accurateResult = (1 - pow(x, 2) / 2) * cos(x) - (x / 2) * sin(x);
        double SN = 0.0;
        double SE = 0.0;

        for (int l = 0; l <= n; l++)
        {
            double result = pow(-1, l) * (2 * pow(l, 2) + 1) / (2 * tgamma(l + 1)) * pow(x, 2 * l);
            SN += result;
        }

        int h = 0;
        double result;

        do
        {
            result = pow(-1, h) * (2 * pow(h, 2) + 1) / (2 * tgamma(h + 1)) * pow(x, 2 * h);
            SE += result;
            h++;
        } while (fabs(result) >= e);

        cout << "X = " << x
             << " SN = " << SN
             << " SE = " << SE
             << " Y = " << accurateResult << endl;
    }

    return 0;
}
