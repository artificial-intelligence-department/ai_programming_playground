#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    int a = 5;
    int b = 3;
    double x, y;
    cout << "Please, enter your value" << endl;
    cin >> x;
    if ( x >= 1 && x <= 2 ) {
        if ( abs(x) < a/b ) {
            y = sin( abs( a*x + b ) );
        } else if ( abs(x) >= a/b ) {
            y = cos( abs( a*x - b ) );
        }
        cout << fixed << setprecision(1) << y << endl;
    } else {
        return 0;
    }
}