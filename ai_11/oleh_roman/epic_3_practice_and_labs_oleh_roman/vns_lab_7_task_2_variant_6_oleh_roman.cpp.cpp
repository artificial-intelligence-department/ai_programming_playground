#include <iostream>
#include <complex>

using namespace std;

double dif(double a, double b) {
    return a - b;
}

complex<double> dif(const complex<double>& a, const complex<double>& b) {
    return a - b;
}

int main() {
    double chuslo1_real, chuslo2_real, chuslo2_imaginary, chuslo1_imaginary;

    cout << "Введіть дійсну частину першого комплексного числа: ";
    cin >> chuslo1_real;
    cout << "Введіть уявну частину першого комплексного числа: ";
    cin >> chuslo1_imaginary;

    cout << "Введіть дійсну частину другого комплексного числа: ";
    cin >> chuslo2_real;
    cout << "Введіть уявну частину другого комплексного числа: ";
    cin >> chuslo2_imaginary;

    complex<double> z1(chuslo1_real, chuslo1_imaginary);
    complex<double> z2(chuslo2_real, chuslo2_imaginary);

    double realDif = dif(chuslo1_real, chuslo2_real);
    cout << "Різниця дійсних чисел: " << realDif << endl;

    complex<double> complexDif = dif(z1, z2);
    cout << "Різниця комплексних чисел: " << complexDif.real() << " + i" << complexDif.imag() << endl;

    return 0;
}
