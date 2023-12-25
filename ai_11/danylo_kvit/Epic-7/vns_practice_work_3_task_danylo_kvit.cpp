#include <iostream>
using namespace std;
int main(){
    cout << "Введіть початкові дані:\n"
            "Радіус підстави (см) >";
    double r;
    cin >> r;
    cout << "Висот циліндра (см) >";
    double h;
    cin >> h;
    cout << "Об'єм >" << h*M_PI*r*r << " см.куб.\n"
                                       "R1 R2 R3:";
    double r1,r2,r3;
    cin >> r1 >> r2 >> r3;
    cout << "Total resistance >" << r1+r2+r3;
}