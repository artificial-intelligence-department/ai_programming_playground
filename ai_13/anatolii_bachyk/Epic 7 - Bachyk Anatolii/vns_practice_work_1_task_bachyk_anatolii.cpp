#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x = 1.23;
    double y = 0.79;
    double b = 1 + pow(tan(x/2),2);

    double denom = pow(y,3)+ fabs(pow(x,2)/ (y + (pow(x,2/3))));
    double numdenom = x / denom;
    double a = y + numdenom;

    cout << a << endl;

    return 0;
}