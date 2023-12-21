#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
for(double x=0.1; x<=0.8; x+=0.07)
{
    double Sn=0;

    for (int j=1; j<=40; j++)
    {
        Sn+=pow(x,j)*sin(j*M_PI/4);
    }

    double S=0, Se=0;
    int n=1;

    S=pow(x,n)*sin(n*M_PI/4);

    while (S>=0.0001)
    {
        S*=(x*sin((M_PI*(n+1))/4))/sin(n*M_PI/4);
        Se+=S;
        n++;
    }
    double y = x*sin(M_PI/4)/(1-2*x*cos(M_PI/4)+pow(x,2));

    cout<<"X="<<x<<" SN="<<Sn<<" SE="<<Se<<" Y="<<y<<"\n";
}
    return 0;
}