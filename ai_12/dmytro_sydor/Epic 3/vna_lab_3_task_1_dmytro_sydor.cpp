#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double epsilon = 0.0001;
int n = 30;

int main()
{

    for (double x = 0.1; x < 1; x += ((1.0 - 0.1) / 10))
    {
        double sn = 0.0;
        double se = 0.0;
        double y = ((1 + pow(x, 2)) / 2) * atan(x) - (x / 2);

        cout << fixed << setprecision(2) << "X = ";

        // Обчислення SN
        for (int i = 1; i <= n; i++)
        {

            sn += ((pow((-1), i + 1)) * (pow(x, 2 * i + 1)) / (4 * i * i - 1));
        }

        // Обчислення SE
        int n = 1;
        double ne = pow(x, 3) / 3;
        while (fabs(ne) >= epsilon)
        {
            se += ne;
            n++;
            ne = (pow(-1, n + 1)) * pow(x, 2 * n + 1) / (4 * pow(x, 2) + 1);
        }

        cout << x << fixed << setprecision(6) << "   SN = " << sn << "   SE = " << se << "   Y = " << y << endl;
    }

    return 0;
}
