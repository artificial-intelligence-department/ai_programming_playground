#include <iostream>
using namespace std;


double substraction(double a, double b){
    return a - b;
}


void substraction(double r1, double c1, double r2, double c2, double &rSubstract, double &complexSubstract){
    rSubstract = r1 - r2;
    complexSubstract = c1 - c2;
}


int main() {
    double a, b;
    cout << "Enter two real numbers: ";
    cin >> a >> b;
    cout << "subtr: " << substraction(a, b) << endl;


    cout << "Enter complex number (numerical value and complex): ";
    double r1, c1;
    cin >> r1 >> c1;


    cout << "Enter second complex number (numerical value and complex): ";
    double r2, c2;
    cin >> r2 >> c2;


    double rSubstract, complexSubstract;
    substraction(r1, c1, r2, c2, rSubstract, complexSubstract);


    cout << "subtr: " << rSubstract << "+(" << complexSubstract << ")i" << endl;


    return 0;
}
