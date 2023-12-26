#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int h = 8, r = 5, R = 2*r;
    float l, S, V;
    l = sqrt(pow(h, 2) + (R - r));
    S = M_PI*(R + r)*l + M_PI*pow(R, 2) + M_PI*pow(r, 2);
    V = M_PI/3*(pow(R, 2) + pow(r, 2) + R*r)*h;
    cout << S << endl << l << endl << V;
    return 0;
}