#include <iostream>
#include <cmath>

using namespace std;

float Byfloat() {
    float a = 1000;
    float b = 0.0001;
    float c, d, e;

    c = (pow((a-b), 3) - (pow(a, 3) - 3 * pow(a, 2) * b));
    d = (pow(b, 3) - 3 * a * pow(b, 2));
    e = c / d;

    return e;
}

double Bydouble() {
    double a = 1000;
    double b = 0.0001;
    double c, d, e;

    c = (pow((a-b), 3) - (pow(a, 3) - 3 * pow(a, 2) * b));
    d = (pow(b, 3) - 3 * a * pow(b, 2));
    e = c / d;

    return e;
}

int main() {

    cout << "On floats: "   << Byfloat()    << endl
         << "On doubles: "  << Bydouble()   << endl;

    return 0;
}