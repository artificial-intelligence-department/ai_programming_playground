#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a = 0.3;
    double b = 0.9;
    double x = 0.53;
    double y = (pow(a, 2*x)+pow(b, -x)*cos(a+b)*x)/abs(x+1);
    double r = sqrt(pow(x, 2)+b)-pow(b, 2)*pow(sin(x+a), 3)/x;
    cout << y << endl;
    cout << r;
    return 0;
}