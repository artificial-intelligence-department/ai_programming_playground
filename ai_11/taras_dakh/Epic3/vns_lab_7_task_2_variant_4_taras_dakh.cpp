#include <iostream>
#include <complex>
using namespace std;

int diff(int a, int b)
{
    return a-b;
}

    complex<double> diff(double a[2], double b[2]) 
{
    complex<double> x1(a[0], b[0]); 
    complex<double> x2(a[1], b[1]); 
    
    return x1 - x2;
}

int main() 
{
    int r = diff(7,  2);
    cout << "Diff of integer numbers: " << r << endl;

    double a[2] = {6.0, 3.0};
    double b[2] = {4.0, 1.0};
    complex<double> r1 = diff(a, b);
    cout << "Diff of complex numbers: " << r1 << endl;

    return 0;
}