#include <iostream>
#include <cmath>

using namespace std;


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "enter the coordinates of the 1st point: " << endl;
    cin >> x1 >> y1;
    cout << "enter the coordinates of the 2nd point: " << endl;
    cin >> x2 >> y2;
    cout << "enter the coordinates of the 3rd point: " << endl;
    cin >> x3 >> y3;
    
    double area = triangleArea(x1, y1, x2, y2, x3, y3);
    cout <<  area << endl;
    
    return 0;
}
