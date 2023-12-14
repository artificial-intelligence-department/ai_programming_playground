#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r;

    cout << "Enter the radius(in meters): ";
    cin >> r;

    
    double v = (4.0 / 3.0) * M_PI * pow(r, 3);

    double s = 4.0 * M_PI * pow(r, 2);

    cout << "Volume of the sphere: " << v << endl;
    cout << "Surface area of the sphere: " << s << endl;

    return 0;
}
