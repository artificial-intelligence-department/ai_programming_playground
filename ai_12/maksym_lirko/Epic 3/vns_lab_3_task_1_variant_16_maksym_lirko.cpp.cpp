#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    const int n=40;
    const double E=0.0001;;
    int k=10;
    double X, SN, SE, SUMA, Y;
    double a=0.6, b=3.14;
    double pi=M_PI;

    for ( X = a; X <= b; X+=(b-a)/k)
    {
        SN=0;
        for (int i = 1; i <n; i++)
        {
            SN+=(cos(2*i-1)*X)/pow(2*i-1,2);
        }

        int i2 =1;
        SUMA=X;
        SE=0;
        while (fabs(SUMA)>=E)
        {
            SUMA=(cos(2*i2-1)*X)/pow(2*i2-1,2);
            SE+=SUMA;
            ++i2;
        }
        
        Y=(pow(pi,2)/8)-(pi/4)*fabs(X);

        cout << "X=" << "   " << setprecision(5) << X << "   ";
        cout << "SN=" << "   " << setprecision(5) << SN << "   ";
        cout << "SE=" << "   " << setprecision(5) << SE << "   ";
        cout << "Y=" << "   " << setprecision(5) << Y << endl;

    }    
    return 0;
}