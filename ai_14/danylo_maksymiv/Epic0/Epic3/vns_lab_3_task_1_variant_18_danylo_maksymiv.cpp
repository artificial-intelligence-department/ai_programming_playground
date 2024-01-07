#include <iostream>
#include <cmath>
using namespace std;
double pi = M_PI;

int main()
{
    double y, eps = 0.0001, se, fraction,sn;
    int nse = 1;

    for(double x = 0.1;x<=0.81;x+=0.07)  //x iteration
    {
        fraction = 0.0;
        se = 0.0;
        nse=1;
        sn = 0.0;
        
        y=0.5-((pi/4)*fabs(sin(x))); //
        
        do //
        {
            fraction = cos(2*x*nse)/(4*pow(nse,2)-1);
            se += fraction;
            nse++;
        } while (fabs(fraction) > eps); 

        fraction = 0.0;

        for(int n =1;n<=50;n++)
        {
            fraction = cos(2*x*n)/(4*pow(n,2)-1);
            sn += fraction;            
        }      

        cout << "X=" << x <<  " SN="<< sn << " SE=" << se << " Y=" << y <<endl;
    }
    return 0;
}
