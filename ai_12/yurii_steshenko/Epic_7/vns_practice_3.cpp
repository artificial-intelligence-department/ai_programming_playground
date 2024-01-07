#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, ha;
    cout << "Enter side and height (cm): ";
    cin >> a >> ha;

    double area = 0.5 * a * ha;
    cout << "Area of triangle (sqcm): " << area << endl;
    
    return 0;
}