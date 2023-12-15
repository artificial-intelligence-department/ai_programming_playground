#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    double a = 0.1;
    double b = 1.0;
    double epsilon = 0.0001;

    int k = 10;

    // X- значення параметра; SN- значення суми для заданого n; 
    //SE- значення суми для заданої точності; Y-точне значення функції.

    double step = (b - a) / k;

    for (double x = a; x <= b; x += step)
    {
        double Sn = 0;
        double Se = 0;
        double y = sin(x);
        for (int n = 0; n <= 10; ++n)
        {
            Sn += pow(-1, n) * pow(x, 2 * n + 1) / tgamma(2 * n + 2);
        }

        for (int n = 0; abs(pow(-1, n) * pow(x, 2 * n + 1) / tgamma(2 * n + 2)) > epsilon; ++n)
        {
            Se += pow(-1, n) * pow(x, 2 * n + 1) / tgamma(2 * n + 2);
        }

        cout << "X = " << x << endl;

        cout << "SN = " << Sn << endl;

        cout << "SE = " << Se << endl;

        cout << "Y = " << y << endl;
    }

    return 0;
}