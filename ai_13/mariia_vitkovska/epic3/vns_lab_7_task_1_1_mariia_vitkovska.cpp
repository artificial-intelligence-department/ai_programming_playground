#include <iostream>
#include <cmath>

using namespace std;

double length( double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
int main() {
    double x1, y1, x2, y2;
    cout << "enter the coordinates of the 1st point: " << endl;
    cin >> x1 >> y1;
    cout << "enter the coordinates of the 2nd point: " << endl;
    cin >> x2 >> y2;
    cout << length(x1, y1, x2, y2);
}