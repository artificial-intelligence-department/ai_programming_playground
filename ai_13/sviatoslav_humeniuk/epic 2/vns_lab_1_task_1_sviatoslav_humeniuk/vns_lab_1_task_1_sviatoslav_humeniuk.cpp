#include <iostream>
#include <string>
#include <math.h>

int main()
{
    double a=100;
    double b=0.001f;
    double c;
    c=(pow(a-b,4)-(pow(a,4)-4*pow(a,3)*b))/(6*pow(a,2)*pow(b,2)-4*a*pow(b,3)+pow(b,4));
    std::cout<<c;
}