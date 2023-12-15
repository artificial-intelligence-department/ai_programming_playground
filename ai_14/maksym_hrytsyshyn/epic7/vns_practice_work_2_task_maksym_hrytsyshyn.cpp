#include <iostream>
#include <cmath>    
using namespace std;

void calc(double x) { // Function for calculating z using pow(), sin() and cos() functions
    double z = (cos(x) - 1) / (x + 1); // formula for z using cos() function
    cout << "x = " << x << "   z = " << z << endl; // Output of z
}

int main() {
    double hx = 0.5;    // Variable declaration and initialization using data type double
    int a = -3;            // Variable declaration and initialization using data type int
    int b = 3;

    for (double x = a; x <= b; x += hx) {               // Loop for x from a to b with step hx
        calc(x);       // Use of the calc() function
    }

    return 0; 

}