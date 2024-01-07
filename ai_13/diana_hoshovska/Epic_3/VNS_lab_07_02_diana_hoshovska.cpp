#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>
using namespace std;

double dec(double a, double b);
double com(double c, double d);

int main(){
    double a, b, c, d;
    dec(a, b);
    com(c, d);
    return 0;
}

double dec(double a, double b){
    //double a, b, 
    double sum1;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    sum1 = a + b;
    cout << "The sum of decimal fraction is " << sum1 << endl;
    return 0;
}

double com(double c, double d){
    double c1, c2, d1, d2, sum2;
    cout << "Enter a numerator and a denumerator for variative c: ";
    cin >> c1 >> c2;
    c = c1/c2;

    cout << "Enter a numerator and a denumerator for variative d: ";
    cin >> d1 >> d2;
    d = d1/d2;

    sum2 = c + d;
    cout << "The sum of common fraction is " << sum2 << endl;
    return 0;
}