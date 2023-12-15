#include <iostream>
#include <math.h>
using namespace std;
int main () {
    double a;
    double b;
    double result;
    cout << "enter a: ";
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    result = (pow(a-b,3)-(pow(a,3)-3*a*pow(b,2)))/(pow(b,3)-3*pow(a,2)*b);
    cout <<"result: " << result;
    return 0;
}
