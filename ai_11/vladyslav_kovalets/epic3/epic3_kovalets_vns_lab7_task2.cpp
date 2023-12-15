#include <iostream>
#include <complex>

int suma_of_numbers(int a, int b) 
{
    return a + b;
}

std::complex<double> suma_of_numbers(double a[2], double b[2]) 
{
    std::complex<double> z1(a[0], b[0]); // 1 + 2i
    std::complex<double> z2(a[1], b[1]); // 2 + 1i

    return z1 + z2;
}

int main() 
{
    int r = suma_of_numbers(3,  4);
    std::cout << "Sum of numbers: " << r << std::endl;

    double a[2] = {1.0, 3.0};
    double b[2] = {2.0, 1.0};
    std::complex<double> r1 = suma_of_numbers(a, b);
    std::cout << "Sum of complex numbers: " << r1 << std::endl;

    return 0;
}
