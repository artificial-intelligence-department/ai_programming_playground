#include <iostream>
#include <cmath>
using namespace std;

double calcS(double x) { // Function for calculating s using pow() function
    return 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4;
}

double calcZ(double x, double y) { // Function for calculating z using pow(), sin() and cos() functions
    return sin(pow(x, 3)) + pow(cos(y), 2);
}

int main() {
    double x = 1.2; // Variable declaration and initialization using data type double
    double y = -0.8; 
    double s = calcS(x); // initialization of s using calcS() function
    double z = calcZ(x, y); // initialization of z using calcZ() function
    cout << "s = " << s << endl; // Output of s
    cout << "z = " << z << endl;
    return 0;

}