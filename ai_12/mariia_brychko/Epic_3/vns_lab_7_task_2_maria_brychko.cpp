#include <iostream>
using namespace std;

double add(double a, double b) {
    return a + b;
}

struct Fraction {
    int numerator;  
    int denominator; 
};


Fraction add (Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

int main () {
    double a1, b1;
    cin >> a1 >> b1;
    cout << "Sum of decimals: " << add(a1, b1) << endl;

    Fraction a2, b2;
    cin >> a2.numerator >> a2.denominator >> b2.numerator >> b2.denominator;
    Fraction result = add(a2, b2);
    cout << "Sum of fractions: " << result.numerator << "/" << result.denominator;

    return 0;
}
