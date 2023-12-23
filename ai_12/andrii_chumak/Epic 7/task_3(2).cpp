#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a,b,h;
    cout << "Please, enter the values (a and b)" << endl;
    cin >> a;
    cin >> b;
    cout << "Enter the height of the trapezoid" << endl;
    cin >> h;
    double S = ( (a + b)/2 ) * h;
    cout << S << endl;
}