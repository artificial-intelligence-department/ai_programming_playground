#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main () {
    double r, h, v;
    
    cout << "Введіть початкові дані: "<< endl;
    cout << "радіус підстави (см) > ";
    cin >> r; // take input
    cout << "висота циліндра (см) > ";
    cin >> h; // take input
    v = M_PI*pow(r,2)*h; // formula for volume
    cout << "Об'єм циліндра : " << v << endl; // display volume
    cout << "Для завершення натисніть клавішу <Enter> ";
    
    return 0;
}