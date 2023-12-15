#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a1=1000, b1=0.0001, d1, c1, e1, res1;
    double a2=1000, b2=0.0001, d2, c2, e2, res2;
    d1 = pow(a1-b1,3);
    c1 = pow(a1, 3);
    e1 = pow(b1,3)-3*a1*b1*b1-3*a1*a1*b1;
    res1 = (d1-c1)/e1;
    d2 = pow(a2-b2,3);
    c2 = pow(a2, 3);
    e2 = pow(b2,3)-3*a2*b2*b2-3*a2*a2*b2;
    res2 = (d2-c2)/e2;
    cout << "RESULT float = " << res1;
    cout << "\nRESULT double = " << res2;
    return 0;
    }