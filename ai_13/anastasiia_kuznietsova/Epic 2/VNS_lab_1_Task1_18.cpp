#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    float a = 1000.0;
    float b = 0.0001;
    float c;
    float d = pow((a-b), 3), e = pow(a, 3), f = pow(b, 3), g = pow(b, 2), h = pow(a, 2);

    c = (d-e) / (f-3*a*g -3*h*b);
//c = (pow((a-b), 3)-(pow(a, 3))) / (pow(b, 3)-3*a*pow(b, 2) -3*pow(a, 2)*b);

    cout<<c;
    
    return 0;
}