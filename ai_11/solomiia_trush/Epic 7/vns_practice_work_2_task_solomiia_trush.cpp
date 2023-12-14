#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double a=2.4, h=0.5;
    double z, x, denominator, numerator;

    for (double x=-3; x<=3; x=x+h) {
        numerator = pow(a,x)*log(abs(x+pow(2,3))); // calculate numerator
        denominator = x+1; // calculate denominator
        z = numerator/denominator; // calculate z
        cout << z << endl; // display z
    }

    return 0;
}