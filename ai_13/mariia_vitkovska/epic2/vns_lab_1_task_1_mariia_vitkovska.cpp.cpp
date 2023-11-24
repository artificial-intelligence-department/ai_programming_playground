#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 1000.0;
    double b = 0.0001;

    double first = (pow (a - b, 2)-(pow(a,2) - 2*a*b))/pow(b,2);
    cout << "Result : " << first << endl;
    return 0;
}