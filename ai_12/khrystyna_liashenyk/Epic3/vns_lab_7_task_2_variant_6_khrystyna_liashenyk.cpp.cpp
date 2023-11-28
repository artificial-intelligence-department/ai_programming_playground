#include <iostream>

using namespace std;
double subtract(double x, double y) {
    return x - y;
}

void subtractComplex(double real1, double imag1, double real2, double imag2, double &real, double &imag) {
    real = subtract(real1, real2);
    imag = subtract(imag1, imag2);
}

int main() {
    double x = 10.5;
    double y = 3.2;
    double result_double = subtract(x, y);
    cout  << result_double << endl;

    double real1 = 5.0;
    double imag1 = 3.0;
    double real2 = 2.5;
    double imag2 = 1.8;

    double real, imag;
    subtractComplex(real1, imag1, real2, imag2, real, imag);

    cout << real << " + " << imag << "i" << endl;

    return 0;
}
