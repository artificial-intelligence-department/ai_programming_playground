#include <iostream>
using namespace std;

double substraction(double a, double b){
    return a - b;
}

void substraction(double r1, double i1, double r2, double i2, double &rSubstract, double &iSubstract){
    rSubstract = r1 - r2;
    iSubstract = i1 - i2;

}

int main() {
    cout << "Enter two real numbers: ";
    double a, b;
    cin >> a >> b;
    cout << "The result of substraction of two real numbers: " << substraction(a, b) << endl;

    cout << "Enter the real and imaginary part of the 1 complex number: ";
    double r1, i1;
    cin >> r1 >> i1;

    cout << "Enter the real and imaginary part of the 2 complex number: ";
    double r2, i2;
    cin >> r2 >> i2;

    double rSubstract, iSubstract;
    substraction(r1, i1, r2, i2, rSubstract, iSubstract);

    cout << "The result of substraction of two complex numbers: " << rSubstract << "+(" << iSubstract << ")i" << endl;



    return 0;
}