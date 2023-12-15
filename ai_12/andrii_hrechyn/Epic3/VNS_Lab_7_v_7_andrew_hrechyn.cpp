#include <iostream>
#include <cstdarg>
#include<complex>
using namespace std;

template<typename T>
T finding_minimum(T k, ...) {
    va_list arguments;
    va_start(arguments, k);

    T minimumargument = va_arg(arguments, T);

    for (int i = 1; i < k; i++) {
        T current = va_arg(arguments, T);
        if (current < minimumargument) {
            minimumargument = current;
        }
    }

    va_end(arguments);

    return minimumargument;
}

double division(int divident, int divisor){
    if(divisor != 0){
    double result = divident / static_cast<double>(divisor);
    return result;
    }
    else{
        cout << "Wrong divisor" << endl;
        return 0;
    }

}
    complex<double>division_of_complex(complex<int>z1, complex<int>z2){
        if(z2.real() != 0 || z2.imag() != 0){
            complex<double> res(static_cast<double>(z1.real()), static_cast<double>(z1.imag()));
        res /= complex<double>(static_cast<double>(z2.real()), static_cast<double>(z2.imag()));
        return res;
        }
        else{
            cout << "Wrong second complex number!";
            return 0;
        }
} 
int main() {
    int divident, divisor;
    double result;

    int minimum_int = finding_minimum<int>(5, 10, 5, 20, 8, 15);
    cout << minimum_int << endl;

    double minimum_double = finding_minimum<double>(4, 0.26, 0.1, 213.3, 0.0213);
    cout << minimum_double << endl;
    
    cout << "Enter divident and divisor: ";
    cin >> divident >> divisor;
    result = division(divident, divisor);
    cout << result << endl;

    
    complex<int>z1 (3, -3);
    complex<int>z2 (5, 6);
    complex<double>res = division_of_complex(z1, z2);
    cout << "Division of 3-3i and 5+6i is: " << res.real() << " + " << res.imag() << "i" << endl;
    return 0;
}
