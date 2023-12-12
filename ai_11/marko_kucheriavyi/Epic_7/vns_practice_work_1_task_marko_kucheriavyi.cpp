#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double P, Q, x = 0.25, y = 0.79, z = 0.81;
    P = (1 + pow(sin(x+1), 2)) / (2 + abs(x - 2*pow(x,3) / (1 + x*x*y*y*y))) + pow(x,4);
    cout << "P = " << P << endl;
    Q = pow(cos(atan(1/z)), 2);
    cout << "Q = " << Q;
    return 0;
}