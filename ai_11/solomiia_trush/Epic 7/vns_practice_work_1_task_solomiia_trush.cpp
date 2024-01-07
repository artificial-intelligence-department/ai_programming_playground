#include <iostream>
#include<cmath>
using namespace std;

int main () {
    const double a=-0.5, b=1.7, t=0.44;
    double y, s;
    double e = exp(1);


    y = pow(e,(-b*t)) * sin(a*t+b) - sqrt(abs(b*t+a)); // calculate the y
    s = b*sin(a*pow(t,2)*cos(2*t))-1; // calculate the s

    cout << "y = " << y << endl;  // display y
    cout << "s = " << s << endl; // display s

    return 0;
}