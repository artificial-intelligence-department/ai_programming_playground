#include <iostream>
#include <cmath>
using namespace std;
// варіант 22

int main()
{
    const double e = 0.0001;
    const double a = 0.1;
    const double b = 1.0;
    const int n = 35;
    const int k = 10;

    for(int i = 0; i <= k; i++)
    {
        double x = a + i*((b-a)/k);
        double exactResult = (1-pow(x, 2)/2)*cos(x) - (x/2)*sin(x);
        double sn = 0.0;
        double se = 0.0;
        double result;

        for(int l = 0; l<=n; l++)
        {
            result =  pow(-1, l)*(2 * pow(l, 2) + 1) / (2 * tgamma(l + 1))*pow(x, 2 * l);
            sn += result;
        }

        int h = 0;
        do
        {
            result =  pow(-1, h)*(2 * pow(h, 2) + 1) / (2 * tgamma(h + 1))*pow(x, 2 * h);
            se += result;
            h++;
        }
        while(fabs(result) < e);

        cout << "X = " << x
             << "   SN = " << sn
             << "   SE = " << se
             << "   Y = "  << exactResult << endl;
    }

    return 0;
}
