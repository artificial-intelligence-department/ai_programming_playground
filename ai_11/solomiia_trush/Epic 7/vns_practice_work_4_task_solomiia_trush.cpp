#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double k=0.5;
    double y, x;

    for (double x=-2; x<=2; x+=k) { // calculate and display table of arguments
        y = -2.4*x + 5*x -3; // formula for y
        cout << y << endl;
    } 

    return 0;
}