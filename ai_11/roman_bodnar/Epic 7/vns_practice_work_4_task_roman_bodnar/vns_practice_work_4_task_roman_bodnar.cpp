#include <iostream>
#include <cmath>
using namespace std;

double calcY(double x) {
    return abs(x - 2) + abs(x + 1);
}

int main() {
    const double STEP   = 0.5,
            START  = -4.0,
            END    = 4.0;
    const double EPSILON = 0.0001;
    const string HEADER = "------------------\n";

    double x = START, y;

    cout << HEADER << "|x\t\ty|\n" << HEADER;
    while (x <= END + EPSILON) {
        y = calcY(x);
        cout << "|" << x << "\t\t" << y << "|" << endl;
        x += STEP;
    }
    cout << HEADER;

    return 0;
}