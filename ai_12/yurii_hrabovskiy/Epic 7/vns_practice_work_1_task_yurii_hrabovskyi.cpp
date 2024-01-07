#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;

int main()
{
    long double a=3.2, b=17.5, x=-4.8;
    long double Y, Z;

    Y=pow(b, 3)*pow(tan(x), 2)-a/pow(sin(x/a), 2);
    Z=a*pow(M_E, -sqrt(3))*cos(b*x/a);

    cout<<Y<<endl<<Z;

    return 0;
}