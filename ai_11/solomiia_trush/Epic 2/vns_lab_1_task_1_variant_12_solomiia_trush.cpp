#include <iostream>
#include <math.h>

using namespace std;

int main () {

    double a;
    double b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    double sum = a+b;
    double addition = pow(a,2) + 2*a*b;
    double numerator = pow(sum,2)-addition;
    double denominator = pow(b,2);
    double result = numerator/denominator;

    cout << "Result : " << result << endl;

    }