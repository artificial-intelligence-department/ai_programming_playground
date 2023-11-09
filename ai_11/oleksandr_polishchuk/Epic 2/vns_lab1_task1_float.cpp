#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, d, e, f, h, g, j;
    a=100;
    b=0.001;
    f=pow((a+b),4);
    e=4*a*b*b*b;
    d=pow(a,4);
    g=pow(b,4);
    h=pow(a,3);
    j=pow(b,3);
    //c=((pow((a+b),4)-(pow(a,4)+4*a*a*a*b))/(6*a*a*b*b+4*a*pow(b,3)+pow(b,4)))//
    c=(f-(d+4*h*b))/(6*a*a*b*b+4*a*j+g);
    cout<<c<<endl;
    return 0;
}