#include <iostream>
#include <cmath>

using namespace std;

const double eps = 0.0001;
double ans = 0.0;
double krok = (0.8-0.1)/10;
double pi = 3.14159265358979323846;

int main()
{
    for (double x = 0.1; x <= 0.8; x += krok)
    {
        double SN = 0;

        double Y = (x * sin (pi/4))/(1 - (2 * x * cos (pi/4))+ (pow (x,2)));

        for(int n_1 = 1; n_1 <= 40; n_1++)
        {
            ans = pow(x,n_1)*sin(n_1 * (pi/4));
            SN += ans;
        }

        double SE = 0;
        int n_2 = 1;
        double ens = pow(x,n_2)*sin(n_2 * (pi/4));

        while (fabs(ens) >= eps)
        {
            SE += ens;
            n_2++;
            ens = pow(x,n_2)*sin(n_2 * (pi/4));
        }

        cout << "X = " << x << " SN = " << SN << " SE = " << SE << " Y = " << Y << endl;
    }

    return 0;
}