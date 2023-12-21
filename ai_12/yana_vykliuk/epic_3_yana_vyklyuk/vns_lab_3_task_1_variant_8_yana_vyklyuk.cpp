#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.0001;
double an = 0.0;
double step = (0.8-0.1)/10;

int main()
{
    for (double x = 0.1; x <= 0.8; x += step)
    {
        double SN = 0;
        
        double Y = (x*sin(M_PI/4))/(1 - (2*x*cos(M_PI/4))+ (pow(x,2)));

        for(int n = 1; n <= 40; n++)
        {
            an = pow(x,n)*sin(n * (M_PI/4));
            SN += an;
        }

        double SE = 0;
        int n2 = 1;
        double en = pow(x,n2)*sin(n2 * (M_PI/4));
        
        while (fabs(en) >= epsilon)
        {
            SE += en;
            n2++;
            en = pow(x,n2)*sin(n2 * (M_PI/4));
        }

        cout << "X = " << x << " SN = " << SN << " SE = " << SE << " Y = " << Y << endl;
    }

    return 0;
}
