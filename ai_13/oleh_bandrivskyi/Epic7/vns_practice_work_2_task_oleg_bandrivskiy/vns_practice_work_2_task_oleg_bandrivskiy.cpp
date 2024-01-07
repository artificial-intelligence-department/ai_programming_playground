#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x_min = 1;
    double x_max = 10;
    double hx = 2;

    double y_min = -4;
    double y_max = 3;
    double hy = 1;


    double x, y;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of y: ";
    cin >> y;

    if (x > y) {
        double z = pow(x, 2) / pow((x - 5), 3);
        cout << "z = " << z << endl;
    } else {
        double z = pow((x - 2), 3) / (y * pow((x - 5), 4));
        cout << "z = " << z << endl;
    }

    return 0;
}
