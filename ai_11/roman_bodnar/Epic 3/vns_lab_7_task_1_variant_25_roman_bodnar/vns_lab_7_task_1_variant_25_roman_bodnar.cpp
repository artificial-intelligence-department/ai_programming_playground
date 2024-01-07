#include <iostream>
#include <cmath>
using namespace std;

double side_length(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 3.0;
    double y2 = 4.0;

    double length = side_length(x1, y1, x2, y2);

    cout << "Side length: " << length << endl;

    return 0;
}
