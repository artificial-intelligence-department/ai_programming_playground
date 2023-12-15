#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float a;
    double b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    double sum = ((pow((a-b),4) - ((pow(a,4)) - 4*pow(a,3)*b + 6*pow(a,2)*pow(b,2)))/(pow(b,4) - 4*a*pow(b,3)));

    cout << "Result: " << sum;
 
    return 0;
}