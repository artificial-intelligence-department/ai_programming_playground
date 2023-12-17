#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    double a, b, x, R, Y;
    a = 0.3;
    b = 0.9;
    x = 0.53;
    Y = (pow(a, 2.0*x)+pow(b,-x)*cos(a+b)*x)/fabs(x+1);
    R = (pow(x*x + b, 0.5) - b*b*pow(sin(x+a),3.0))/x;
    cout<<"Y = "<<Y<<endl;
    cout<<"R = "<<R;
    return 0;
}
