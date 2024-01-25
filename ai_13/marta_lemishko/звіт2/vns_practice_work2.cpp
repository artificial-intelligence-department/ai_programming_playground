#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double h_x = 0.21;
    double h_a = 0.1;
    double x = 0.5;

    while (x <= 3.1) {
        double a = -0.1;
        double b = 1.5;
        double y;

        if (x < b) {
            y = sin(fabs(a * x + pow(b, a)));
        } else {
            y = cos(fabs(a * x - pow(b, a)));
        }

        cout << "For x = " << x << ", y = " << y << endl;
        x += h_x;
        a += h_a;
    }

    return 0;
}

