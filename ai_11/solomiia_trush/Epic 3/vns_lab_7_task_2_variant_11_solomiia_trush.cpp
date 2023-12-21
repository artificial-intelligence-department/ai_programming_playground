#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int addition (int a, int b) {
    int sum = a+b;
    return sum;
}

complex<double> addition (complex<double> a , complex<double> b ) {
    complex<double> sum = a+b;
    return sum;
}

int main () {

    complex<double> complex_number=addition ({2.0, 3.0}, {5.0, 8.0});
    cout << "Addition of integers : " << addition (4,5) << endl;
    cout << "Addition of complex numbers : " << complex_number.real() << "+" << complex_number.imag() << "i" << endl;

}