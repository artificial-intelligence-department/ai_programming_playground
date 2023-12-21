#include <iostream>
#include <stdarg.h>
#include <iomanip>
#include <complex>

using namespace std;

float mult(int k, ...);
float sum(float x, float y);
complex<int> sum(complex<int> z1, complex<int> z2);

int main()
{   
    cout << fixed << setprecision(4);
    cout << "TASK 1\n";

    cout << "Product(10.1, 2.5, 23.13) = " << mult(2, 10.1, 2.5, 23.13) << endl;
    cout << "Product(2.32, 21.42, 23.1, 2.3, 2.32, 1.23, 13.21) = " << mult(7, 2.32, 21.42, 23.1, 2.3, 2.32, 1.23, 13.21) << endl;
    cout << "Product(13.13, 10.1, 2.32, 21.42, 23.1, 2.3, 2.32, 1.23, 13.21, 12.23, 0.002) = " << 
        mult(11, 13.13, 10.1, 2.32, 21.42, 23.1, 2.3, 2.32, 1.23, 13.21, 12.23, 0.002) << endl;

    
    cout << "\n\nTASK 2\n";


    cout << "Sum of 3.5 and 5.4 = " << sum(3.5, 5.4) << endl;

    complex<int> z1 (10, -2);
    complex<int> z2 (-23, 14);
    complex<int> s = sum(z1, z2);
    cout << "Sum of 10 - 2i and -23 + 14i = " << real(s) << " + " << imag(s) << "i\n";

    return 0;
}

float mult(int k, ...)
{   
    va_list ptr;
    va_start(ptr, k);

    float result = 1;

    while(k--)
    {
        result *= va_arg(ptr, double);
    }

    va_end(ptr);

    return result;
}
float sum(float x, float y)
{
    return x + y;
}
complex<int> sum(complex<int> z1, complex<int> z2)
{
    return z1 + z2;
}
