#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define N 40
#define E 0.0001


int main()
{   
    double X, SN, SE, s, Y;
    cout << fixed << setprecision(4);

    for(double i = 0.2; i <= 1.8; i += 0.16)
    {
        X = i * M_PI;
        cout << "X = " << X << "    ";

        SN = 0;
        for(int n = 1; n <= N; n++)
        {
            SN += cos(n * X) / n;
        }
        cout << "SN = " << SN << "    ";


        s = cos(X);
        SE = s;
        for(int n = 2; E / 10 <= abs(s); n++)
        {
            s = cos(n * X) / n;
            SE += s;
        }
        cout << "SE = " << SE << "    ";

        Y = -1 * log( abs( 2 * sin(X / 2) ) );
        cout << "Y = "<< Y << endl;
    }

    return 0;
}
