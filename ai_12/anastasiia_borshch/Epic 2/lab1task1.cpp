#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int main() {
    double a,b,c,d,e,f,g,h,x,m,t,n;
    cout << "Enter 100:";
    cin >> a;
    cout << "Enter 0.001:";
    cin >> b;
    c=pow(a+b,4);
    d=pow(a,4);
    e=pow(a,3);
    f=pow(a,2);
    g=pow(b,2);
    h=pow(b,3);
    x=pow(b,4);
    n=d+4*e*b+6*f*g;
    m=4*a*h+x;
    t=(c-n)/m;

    cout << t;
    return 0;
}