#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 0.25;
    double y = 1.31;
    double a = 3.5;
    double b = 0.9;
    const double PI = 3.1415926;

    double A = pow(sin(a * pow(x, 3) + b * pow(y, 2) - a * b), 3); 
    double B = pow(pow(a * pow(x, 3) + b * pow(y, 2) - a, 2) + PI, 1/3);
    double C = tan(a * pow(x, 3) + b * pow(y, 2) - a * b);
    double P = fabs((A/B)+C);
    cout << "Result: " << P <<endl;

    return 0;
}
