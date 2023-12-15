#include <iostream>
using namespace std;

double Mult(double a, double b)
{
    return a * b;
}

void Mult(double real1, double real2, double im1, double im2, double& resReal, double& resIm)
{
    resReal = real1 * real2 - im1 * im2;
    resIm = real1 * im2 + real2 * im1;
}

int main()
{
    double c, d;
    cin >> c >> d;
    double result1 = Mult(c, d);
    cout << result1 << endl;

    double real1, real2, im1, im2, resReal, resIm;
    cin >> real1 >> real2 >> im1 >> im2;
    Mult(real1, real2, im1, im2, resReal, resIm);
    cout << resReal << "+" << resIm << "i";
    return 0;
}