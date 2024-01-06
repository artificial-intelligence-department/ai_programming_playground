#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x, y;

    cout << "Table of values for the function y = |x| for x from -4 to 4 with a step of 0.5:" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|   x      |   y = |x|   |" << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << fixed << setprecision(2); 

    for (x = -4.0; x <= 4.0; x += 0.5) {
        y = abs(x); 

        
        cout << "| " << setw(7) << x << " | " << setw(10) << y << " |" << endl;
    }

    cout << "---------------------------------------------------------" << endl;

    return 0;
}
