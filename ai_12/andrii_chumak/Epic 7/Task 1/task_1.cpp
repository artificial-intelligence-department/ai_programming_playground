#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double x = 1.2;
    double y = -0.8;
    double s = 1 + x + (pow(x, 2)/2) + (pow(x, 3)/3) + (pow(x, 4)/4);
    double z = sin(pow(x, 3)) + cos(pow(y, 2)) ;
    cout << s << endl;
    cout << z << endl;
}