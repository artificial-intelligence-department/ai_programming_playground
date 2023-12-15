#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

int Multi(int a, int b)
{
 return a * b;
}

complex<double> Multi(complex<double> z1, complex<double> z2)
{
 return z1 * z2;
}



int main()
{
 int r = Multi(5, 3);
 cout << "Multiplication " << r << endl;

 //complex<double> c = Multi((2.0, 3.0), (1.0, -2.0));
 complex<double> z1(7.0, 6.0); // 7 + 6i
 complex<double> z2(9.0, 4.0); // 9 + 4i
 complex<double> c = Multi(z1, z2);
 cout << "Complex Multiplication " << c.real() << "+" << c.imag() << "i" << endl;
 
 return 0;
}