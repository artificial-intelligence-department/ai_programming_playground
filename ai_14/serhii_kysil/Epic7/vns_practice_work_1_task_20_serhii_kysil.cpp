#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, x, s, d, l;
    a = 0.5;
    b = 2.9;
    x = 0.3;
    s = (pow(a, x) + pow(b, -x)*sin(a - b))/(sqrt(fabs(a- b)));
    d = a*exp(-sqrt(a))*cos((b*x)/a);
    cout<<s<<"\n"<<d;
    return 0;
}