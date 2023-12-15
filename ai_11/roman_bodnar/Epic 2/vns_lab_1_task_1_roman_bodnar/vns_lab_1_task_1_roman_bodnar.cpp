#include <iostream>
#include <cmath>
using namespace std;

void OnDoubles() {
    double a = 1000;
    double b = 0.0001;
    double c = a + b;
    double d = pow (a, 2) + 2 * a * b;
    cout << "On doubles: " << (pow (c, 2 ) - d)/ pow (b, 2);
}

void OnFloats() {
    float a = 1000;
    float b = 0.0001;
    float c = a + b;
    float d = pow (a, 2) + 2 * a * b;
    cout << "On floats: " << (pow (c, 2 ) - d)/ pow (b, 2);
}

int main() {
    OnFloats();
    OnDoubles();

    return 0;
}