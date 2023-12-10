#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double pi = M_PI; 
    double x, y, z, a, b, c, d;
    x = 1.45;
    y = -1.22;
    z = 3.5;

    b = 1 + ((pow(z,2))/(3 + (pow(z,2)/5)));
    
    c = 2*cos(x - (pi/6))*b;

    d = 1/2 + pow(sin(y),2);

    a = c / d;
    
    cout << "Result: " << a;

}
 